#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll gcd(ll a, ll b) {
   if(a<b) swap(a, b);
   if(a%b==0) return b;
   else return gcd(b, a%b);
}
ll lcm(ll a, ll b) {
   return a/gcd(a,b)*b;
}

int main(){
   ll a, b;
   cin>>a>>b;

   ll l=lcm(a, b);
   cout<< l <<endl;
   return 0;
}
