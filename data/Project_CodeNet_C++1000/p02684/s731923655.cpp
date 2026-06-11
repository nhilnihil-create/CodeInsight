#include<iostream>
#include<vector>
#define ll long long
using namespace std;

vector<ll> flag(300000,-1);
int main(){
    ll N,K;
    cin>>N>>K;
    vector<ll> A(N+2);
    for(ll i=1;i<=N;i++){
        cin>>A[i];
    }
    ll unit;
    ll now=1;
    flag[now]=0;
    for(ll i=1;i<=K;i++){
        now=A[now];
        if(flag[now]!=-1){
            unit=i-flag[now];
            break;
        }else flag[now]=i;
    }
    if(unit!=0){
        ll C=(K-flag[now])/unit;
        for(ll i=flag[now]+C*unit+1;i<=K;i++){
            now=A[now];
        }
    }
    
    cout<<now<<endl;
    return 0;
}