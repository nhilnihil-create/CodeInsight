#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll mod=1000000007;
const int MAX_N = 1000;         // n の最大値
 
// nCk を取得
double nCk(int n, int k) {
double res=1.0;
for(int i=0; i<n; i++){
res*=0.5;}
for(int i=0; i<k; i++){
res*=(double)(n-i);
res/=(double)(k-i);
}
return res;}
 
int main() {
ll a,b,c,d;
cin>>a>>b>>c>>d;
ll ac=0;
ll ad=0;
ll bc=0;
ll bd=0;
a--;
ac=a/c;
ad=a/d;
bc=b/c;
bd=b/d;
ll acd=0;
ll bcd=0;
ll q=__gcd(c,d);
q=c*d/q;
acd=a/(q);
bcd=b/(q);
cout<<(b+bcd-bc-bd)-(a+acd-ac-ad)<<endl;}
