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
string s,k="RRR";
cin>>s;
ll c=0;
for(int i=0; i<3; i++){
    if(s[i]==k[i]){c++;}
    if(c!=0 && s[i]!=k[i]){break;}
}

cout<<c;
return 0;
}
