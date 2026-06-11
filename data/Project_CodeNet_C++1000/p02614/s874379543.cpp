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
 
int run_test(){
      int r,c,k;
      cin >> r >> c >> k;
      int arr[r][c];
      for(int i =0; i<r; i++){
            for(int j = 0; j<c; j++){
                  char t;
                  cin >> t;
                  if(t == '#'){
                        arr[i][j] = 1;
                  }
                  else{
                        arr[i][j] = 0;
                  }
            }
      }
      int ans = 0;
      for(int rmask = 0; rmask < (1 << r); rmask++){
            for(int cmask =0; cmask < (1 << c); cmask++){
                  int b = 0;
                  for(int i =0; i < r; i++){
                        for(int j=0; j<c; j++){
                             if(((rmask >> i) & 1) == 0 && ((cmask >> j) & 1)== 0 && arr[i][j] == 1) b++;
                        }
                  }
                  if(b == k) ans++;
            }
      }
      cout << ans;
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