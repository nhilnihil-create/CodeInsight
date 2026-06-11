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
int main(){
string a,s;
cin>>a>>s;
ll k,p=0,l=0,m=1e5;
for(int i=0; i<a.size(); i++){
 p=0;
for(int j=0; j<s.size(); j++){
        if((i+j)>=a.size()){l++; break;}
        else{
if(s[j]!=a[i+j]){p++;}

        }
 }
 if(l==0){
 m=min(m,p); }}
 cout<<m;

return 0;
}
