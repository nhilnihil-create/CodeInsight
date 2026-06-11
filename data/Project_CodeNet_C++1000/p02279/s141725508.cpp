#include <stdio.h>
#include <vector>
using namespace std;
struct tree{
    int p;
    int pos;
    vector<int> sons;
    bool root;
    bool leaf;
};
tree map[100000];
void build(int now){
    for(int i=0;i<map[now].sons.size();i++){
        map[map[now].sons[i]].pos=map[now].pos+1;
        map[map[now].sons[i]].p=now;
        build(map[now].sons[i]);
    }
}
int main(){
    int n,l,k,r;
    scanf("%d",&n);
    for(int i=0;i<n;i++)map[i].root=true;
    for(int i=0;i<n;i++){
        scanf("%d%d",&l,&k);
        if(k==0)map[l].leaf=true;
        else map[l].leaf=false;
        for(int j=0;j<k;j++){
            scanf("%d",&r);
            map[l].sons.push_back(r);
            map[r].root=false;
        }
    }
    for(int i=0;i<n;i++)if(map[i].root){
        map[i].p=-1;
        map[i].pos=0;
        build(i);
    }
    for(int i=0;i<n;i++){
        printf("node %d: parent = %d, depth = %d, ",i,map[i].p,map[i].pos);
        if(map[i].root)printf("root, [");
        else if(map[i].leaf)printf("leaf, [");
        else printf("internal node, [");
        if(!map[i].leaf){
            printf("%d",map[i].sons[0]);
            for(int j=1;j<map[i].sons.size();j++)printf(", %d",map[i].sons[j]);
        }
        printf("]\n");
    }
}