#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int gcd(int a, int b) {
   if(a<b) swap(a, b);
   return b?gcd(b,a%b):a;
}
int lcm(int a, int b) {
   ll ret=(ll)a/gcd(a,b)*b;
   if(ret>1000000000) return INT_MAX;
   else return ret;
}

int main(){
   int n, m;
   cin>>n>>m;
   vector<int> a(n);
   rep(i, n) cin>>a[i];

   bool ok=true;
   rep(i, n) if(a[i]%2==1) ok=false;

   rep(i, n) a[i]/=2;
   int l=1;
   rep(i, n) l=lcm(l, a[i]);
   rep(i, n){
      int b=l/a[i];
      if(b%2==0) ok=false;
   }
   int num=m/l - m/((ll)l*2);

   if(ok) cout<<num<<endl;
   else cout<<0<<endl;

   return 0;
}
