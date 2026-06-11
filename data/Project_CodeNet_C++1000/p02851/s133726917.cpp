#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   int n, k;
   cin>>n>>k;
   vector<int> a(n);
   rep(i, n) cin>>a[i];

   vector<int> s(n+1);
   s[0]=0;
   rep(i, n) s[i+1]=(s[i]+a[i])%k;

   rep(i, n+1) s[i]=(s[i]-i%k+k)%k;

   map<int, int> ma;
   ll cnt=0;
   rep(i, n+1){
      if(i-k>=0) ma[s[i-k]]--;
      cnt+= ma[s[i]];
      ma[s[i]]++;
   }

   cout<<cnt<<endl;
   return 0;
}
