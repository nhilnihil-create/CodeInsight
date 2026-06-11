#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
using P = pair <int, int>;
 
ll MOD = 1000000007;
ll INF =1<<29;
 
int main(){
     int n,k;
     cin >> n >> k;
     vector<int> p(n);
     rep(i,n)cin >> p[i];
     int tot = 0;
     int omax=-1;
     if(k==1){
        rep(i,n){
            omax = max(omax,p[i]);
        }
        double oans = double(omax+1)/2;
        cout << fixed<<setprecision(8) << oans <<endl;
        return 0;
     }
     double nans;
     if(k==n){
         rep(i,n){
             nans += double(p[i]+1)/2;
         }
         cout << fixed <<setprecision(8) << nans <<endl;
         return 0;
     }
     vector<int> s(n);
     s[0]=p[0];
     rep(i,n-1){
         s[i+1] = s[i]+p[i+1];
     }
     int ma = s[k-1];
     int ans;
     for(int i = 1;i+k<n;++i){
          if(s[i+k]-s[i]>ma){
              ma = s[i+k]-s[i];
              ans = i;
          }
     }
     double kita =0;
     for(int i = ans;i<ans+k;++i){
          kita+=(double)(p[i+1]+1)/2;
     }
     cout << fixed<<setprecision(8)<<kita <<endl;
}