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
ll n;
cin>>n;
ll a[n],s=0,p;
for(int i=0; i<n; i++){cin>>a[i];}
for(int i=1; i<n; i++){
    if(a[i-1]>a[i]){
            p=a[i-1]-a[i]; s=s+p;
        a[i]=a[i-1];

    }
}
cout<<s;

return 0;
}
