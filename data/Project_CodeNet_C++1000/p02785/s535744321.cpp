#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   int n, k;
   cin>>n>>k;
   vector<int> h(n);
   rep(i, n) cin>>h[i];

   sort(h.rbegin(), h.rend());
   ll cnt=0;
   for(int i=k; i<n; i++) cnt+=h[i];

   cout<<cnt<<endl;
   return 0;
}
