#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,s,e) for(int i=s;i<e;i++)
#define endl '\n'

int main(){
    ll N;cin>>N;
    ll sum=0;
    rep(i,1,N+1){
        ll Y=(ll)N/i;
        sum+=Y*(Y+1)*i/2;
    }
    cout<<sum<<endl;
}