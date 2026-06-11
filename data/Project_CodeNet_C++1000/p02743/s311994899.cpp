#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
   ll a,b,c;
   cin>>a>>b>>c;
   ll l=4*a*b;
   ll r=(c-a-b)*(c-a-b);

   if(c-a-b<0) cout<<"No"<<endl;
   else if(l<r) cout<<"Yes"<<endl;
   else cout<<"No"<<endl;
}