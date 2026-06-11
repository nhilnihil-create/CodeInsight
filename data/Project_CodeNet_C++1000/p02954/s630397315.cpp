#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    string S;
    cin>>S;
    ll N = S.size();
    vector<ll> res(N,0);
    ll sum=0;
    for(ll i=0;i-1<N;i++)
    {
        if(S[i]=='R') {
            sum++;
            if(S[i+1]=='L'){
                res[i+1]+=(int)(sum/2);
                res[i]+=(int)((sum+1)/2);
            }
        }else{
            sum=0;
        }
    }
    sum=0;
    for(ll i=N-1;0<i;i--)
    {
        if(S[i]=='L') {
            sum++;
            if(S[i-1]=='R'){
                res[i-1]+=(int)(sum/2);
                res[i]+=(int)((sum+1)/2);
            }
        }else{
            sum=0;
        }
    }

    for(ll i=0;i<N;i++){
        cout<<res[i];
        if(i!=N-1)cout<<' ';
    }
}