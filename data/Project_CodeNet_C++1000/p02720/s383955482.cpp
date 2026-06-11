
#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<long long , long long>
#define pb push_back
#define ll long long
#define ld long double
#define precision(x,d) cout<<fixed<<setprecision(d)<<x
#define fill(a,b) memset((a),(b),sizeof((a)))
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL));
ll power(ll x,ll y,ll m){ll r=1;for(;y;y>>=1){if(y&1)r=r*x%m;x=x*x%m;}return r;}
const ll mod = 1e9 + 7;
const ld pi = 3.14159265358979;
    
int run_test(){
    int k;
    cin >> k;
    if(k <= 9){
        cout << k;
        return 0;
    }
    queue<int> q;
    for(ll i=1; i <= 9; i++){
        q.push(i);
    }
    int count = 9;
    while(count != k){
        ll a = q.front();
        q.pop();
        int t = a % 10;
        for(int i=-1; i<=1; i++){
            if(t + i <= 9 && t + i >= 0){
                string s = to_string(a);
                char p = (t + i) + '0';
                s = s + p;
                count++;
                if(count == k){
                    cout << s;
                    return 0;
                }
                q.push(stoll(s));
            }
        }
    }
    return 0;
}
    
int main(){
   FAST;
    ll t;
    t = 1;
     
    while(t--){
        run_test();
    }
}