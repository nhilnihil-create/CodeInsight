#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   int a, b;
   cin>>a>>b;

   if(a<=b) rep(i, b) cout<<a;
   else rep(i, a) cout<<b;
   cout<<endl;
   return 0;
}
