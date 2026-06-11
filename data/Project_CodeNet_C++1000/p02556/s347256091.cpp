#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define ld  long double
#define endl '\n'
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll MOD = (ll)1e9+7;
const double PI = 3.141592653589793238463;
const int MAXN = 1000030;
int main() {
   int n;
   cin>>n;
    vector<ll> plus,minus;
   for(int i=0;i<n;i++){
       ll a,b;
       cin>>a>>b;
       plus.push_back(a+b);
       minus.push_back(a-b);
   }
   sort(plus.begin(),plus.end());
   sort(minus.begin(),minus.end());
   cout<<max((plus[n-1]-plus[0]),(minus[n-1]-minus[0]))<<endl;
  
    return 0;
}