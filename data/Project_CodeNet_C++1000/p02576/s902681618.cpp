#include<bits/stdc++.h>
typedef  long long int ll;
typedef long double ld;
#define pb  push_back
#define vll vector<ll>
#define mll map<ll,ll>
const double PI = 2*acos(0.0);
#define gcd(a,b)   __gcd((a),(b))
#define lcm(a,b)   ((a)/(__gcd((a),(b)))*(b))
#define INF         LLONG_MAX
#define ln  INT_MAX
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
int main() {
ll n,x,t;
cin>>n>>x>>t;
if(n%x!=0){n=n/x; n++;}
else{n=n/x;}
cout<<n*t;
return 0;
}
