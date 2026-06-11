#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   int n;
   cin>>n;
   vector<int> a(n);
   rep(i, n) cin>>a[i];

   int nxt=1, cnt=0;
   rep(i, n){
      if(a[i]==nxt) nxt++;
      else cnt++;
   }

   if(cnt==n) cout<<(-1)<<endl;
   else cout<<cnt<<endl;
   return 0;
}
