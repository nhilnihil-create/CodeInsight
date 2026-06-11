#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
ll mod = 1000000007;
ll inf = 1e18;
int main(){

    int k;
    cin >> k;
    queue<ll> que;
    rep2(i,1,10) que.push(i);

    ll ans;
    rep(i,k){
        ans=que.front();
        que.pop();
        if(ans%10!=0) que.push(ans*10+ans%10-1);
        que.push(ans*10+ans%10);
        if(ans%10!=9) que.push(ans*10+ans%10+1);
    }

    cout << ans << endl;
    
    return 0;
}