#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
const ll mod = 1e9 + 7;
int main(){
ll k;cin >> k;
deque<ll>d;
if(k<10){cout << k;return 0;}
for(ll i = 1;i<10;i++) d.push_back(i);
k -= 9;
bool ok = 0;
while(true){
    ll temp = d.front();
    ll r = temp%10;
    d.pop_front();
    for(ll i = -1;i<=1;i++){
        if(r==0&&i==-1) continue;
        if(r==9&&i==1) continue;
        d.push_back(temp*10+r+i);
        k--;
        if(!k) {cout << d.back();return 0;}
    }
}
return 0;
}