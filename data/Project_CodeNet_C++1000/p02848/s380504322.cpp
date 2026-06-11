#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   int k;
   cin>>k;
   string s;
   cin>>s;

   rep(i, s.size()) s[i]=(s[i]-'A'+k)%26+'A';
   cout<<s<<endl;
   return 0;
}
