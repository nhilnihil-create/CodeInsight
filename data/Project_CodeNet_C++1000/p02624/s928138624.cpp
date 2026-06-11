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

ll arr[10000002];

int run_test(){
      int n;
      cin >> n;
      cout << arr[n] << "\n";
      return 0; 
}
 
int main(){
    FAST;
    ll t;
    t = 1;

    for(int i = 1; i<=10000000; i++){
            for(int j = i; j <= 10000000; j+=i){
                  arr[j]++;
            } 
    }
    ll sum = 0, count = 1;
    for(int i=1; i<=10000000; i++){
            sum += arr[i]*(count++);
            arr[i] = sum;  
    }
 
    while(t--){
        run_test();
    }
}