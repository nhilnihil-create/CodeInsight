#include<bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    ll N;cin>>N;
    vector<ll>A(N+1);
    rep(i,N+1){
        cin>>A.at(i);
    }
    vector<ll>Ans(N+1);
    vector<ll>B(N+1);
    B.at(N)=A.at(N);
    for(int i=N-1;i>=0;i--){
        B.at(i)=B.at(i+1)+A.at(i);
    }
    ll sum=1;
    bool flag=true;
    Ans[0]=1;
    rep(i,N){
        Ans[i+1]=min((Ans[i]-A[i])*2,B[i+1]);
        if(Ans[i+1]<=0){
            flag=false;
        }
    }
    rep(i,N){
        if(Ans[i+1]<Ans[i]-A[i]){
            flag=false;
        }
        if(Ans[i+1]<A[i+1]){
            flag=false;
        }
    }
    if(Ans[N]!=A[N]){
        flag=false;
    }
    rep(i,N){
        sum+=Ans[i+1];
    }
    if(flag){
        cout<<sum<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}

    