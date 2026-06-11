#include<bits/stdc++.h>
using namespace std;

vector<int> to[200005];
int check[200005];
queue<int> q;
int S,T;

void kkp(int v){
    for(int u : to[v]){
        for(int w : to[u]){
            for(int x : to[w]){
                if(check[x]==0){
                    q.push(x);
                    check[x]++;
                }
                if(check[T-1]>0)break;
            }
            if(check[T-1]>0)break;
            }
        if(check[T-1]>0)break;
    }
}

int main(){
    int N,M;
    cin >> N >> M;
    int i,j,u,v;
    for(i=0;i<M;i++){
        cin >> u >> v;
        to[u-1].push_back(v-1);
    }
    cin >> S >> T;
    kkp(S-1);
    if(check[T-1]>0)cout << 1 << endl;
    else{
        int flag=2;
        int tmp=q.size();
        int count=0;
        while(!q.empty()){
            kkp(q.front());
            q.pop();
            count++;
            if(check[T-1]>0)break;
            if(tmp==count){
                flag++;
                count=0;
                tmp=q.size();
            }
        }
        if(check[T-1]>0)cout << flag << endl;
        else cout << -1 << endl;
}}