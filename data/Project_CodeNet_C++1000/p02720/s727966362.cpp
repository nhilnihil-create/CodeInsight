#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int K;
    cin >> K;

    if(K<10){
        cout<<K<<endl;
        return 0;
    }

    queue<ll> q;
    rep(i, 9){
        q.push(i+1);
    }
    ll num;
    rep(i, K){
        num=q.front();
        q.pop();
        if(num%10 != 0) q.push(10*num+num%10-1);
        q.push(10*num+num%10);
        if(num%10 != 9) q.push(10*num+num%10+1);
    }

    ll ans=num;
    cout<<ans<<endl;

    return 0;
}