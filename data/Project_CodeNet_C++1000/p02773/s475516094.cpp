#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   int n;
   cin>>n;
   vector<string> s(n);
   rep(i, n) cin>>s[i];

   map<string, int> ma;
   rep(i, n) ma[s[i]]++;
   int mx=0;
   for(auto p : ma) mx=max(mx, p.second);
   vector<string> li;
   for(auto p : ma) if(p.second==mx) li.push_back(p.first);
   sort(li.begin(), li.end());

   for(string t : li) cout<<t<<endl;
   return 0;
}
