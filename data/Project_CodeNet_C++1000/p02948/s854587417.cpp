#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using Graph=vector<vector<ll>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main(){
    int N,M;
    cin>>N>>M;
    Graph G(M);
    rep(i,N){
        int A,B;
        cin>>A>>B;
        if(A<=M){
            A--;
            G[A].push_back(B);
        }
    }
    ll sum=0;
    priority_queue<ll>list;
    rep(i,M){
        if(G[i].size()>0){
            rep(j,G[i].size()){
                list.push(G[i][j]);  
            }
        }
        if(list.size()>0){
            sum=sum+list.top();
            list.pop();
        }       
    }
    cout<<sum<<endl;
}