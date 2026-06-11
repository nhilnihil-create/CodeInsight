#include<cstdio>
#include<vector>
#include<queue>
#define N 10000
using namespace std;

int inNum[N]={0};
int V,E;
vector<int> M[N];
vector<bool> visited(N,0);
void topology(){
    queue<int> Q;
    vector<int> ans;
    for(int i=0;i<V;i++){
        if(inNum[i]==0) Q.push(i);
    }
    while(!Q.empty()){
        int node=Q.front();
        Q.pop();
        visited[node]=true;
        ans.push_back(node);
        for(int i=0;i<M[node].size();i++){
            inNum[M[node][i]]--;
            if(!visited[M[node][i]] && inNum[M[node][i]]==0){
                Q.push(M[node][i]);
            }
        }

    }
    if(ans.size()<V){
        printf("Wrong\n");
        return;
    }else{
        for(int i=0;i<ans.size();i++){
            printf("%d\n",ans[i]);
        }
    }
}

int main(){
    scanf("%d%d",&V,&E);
    for(int i=0;i<V;i++){
        inNum[i]=0;
    }
    int s,t;
    for(int i=0;i<E;i++){
        scanf("%d%d",&s,&t);
        inNum[t]++;
        M[s].push_back(t);
    }

    topology();
    return 0;

}

