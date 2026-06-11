#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    ll k;
    cin>>k;
    queue<ll> q;
    for(int i = 1; i < 10; i++){
        q.push(i);
    }
    ll t = 0;
    while(1){
        t++;
        ll x = q.front();
        if(t == k){
            cout<<x;
            return 0;
        }
        q.pop();
        if(x%10 != 0) q.push(x*10+(x%10)-1);
        q.push(x*10+x%10);
        if(x%10 != 9) q.push(x*10+x%10+1);
    }
}