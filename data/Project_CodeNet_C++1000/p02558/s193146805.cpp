#include <iostream>
using namespace std;
int N, Q;
int root[200005];

int find(int idx){
    if (idx == root[idx])
        return idx;

    int pidx = root[idx];
    root[idx] = find(pidx);
    return root[idx];
}

void join(int u, int v){
    int ru = find(u);
    int rv = find(v);
    root[rv] = ru;
}

int main(){
    scanf("%d%d",&N,&Q);

    for(int i = 0; i <= N; ++i)
        root[i] = i;

    for(int i = 0; i < Q; ++i){
        int t, u ,v;
        scanf("%d%d%d",&t,&u,&v);
        if(t == 0){
            join(u,v);
        }else{
            int ru = find(u);
            int rv = find(v);
            printf("%d\n",(ru==rv)?1:0);
        }
            
    }
}