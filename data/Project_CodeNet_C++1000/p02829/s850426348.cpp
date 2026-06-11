#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   int a, b;
   cin>>a>>b;

   for(int c=1; c<=3; c++) if(c!=a && c!=b) cout<<c<<endl;
   return 0;
}
