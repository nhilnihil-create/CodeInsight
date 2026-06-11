#include <bits/stdc++.h>
#define ll long long
#define PB push_back
#define MP make_pair

#define REP(i, n) for(int i=0;i<(int)(n);++i)
#define FOR(i,l,h) for(int i=(int)(l);i<=(int)(h);++i)
#define FORD(i,h,l) for(int i=(int)(h);i>=(int)(l);--i)

#define max(a,b) a>b?a:b
#define min(a,b) a>b?b:a

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

#define dump(x)  cerr << #x << " = " << (x) << endl
#define ALL(t) (t).begin(),(t).end()

using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;cin>>n>>k;
    string s;
    cin>>s;
    ll int cnt = 0;
    ll int a[n+2];
    ll int mul = 1;
    if(k == 2 || k == 5){
        for (size_t i = 0; i < n; i++) {
            if((s[i] - '0') % k == 0) {
                cnt += (i+1);
            }
        }
        cout<<cnt<<"\n";
    }
    else{
        reverse(s.begin(),s.end());
           for (size_t i = 0; i < n; i++) {
               a[i] = ((s[i] - '0')*mul) % k;
               mul = (mul*10) % k;
           }
           ll int mod[k+2];
           memset(mod , 0, sizeof(mod));
           ll int prefix = 0;
           for (size_t i = 0; i < n; i++) {
               prefix += a[n-(i+1)];
               mod[ ((prefix % k) + k) % k ]++;
           }
           for (size_t i = 0; i < k; i++) {
               if(mod[i] > 1){
                   cnt += ((ll)mod[i]*(mod[i]-1))/2;
               }
           }
           cnt += mod[0];
           cout<<cnt<<"\n";
       }

    return 0;

}
