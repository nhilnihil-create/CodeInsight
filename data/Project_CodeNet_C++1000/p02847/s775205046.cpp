#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   string s;
   cin>>s;

   string ws[]={"SUN", "MON" ,"TUE", "WED", "THU", "FRI", "SAT"};
   int wd;
   rep(i, 7) if(s==ws[i]) wd=i;
   int ans=7-wd;

   cout<<ans<<endl;
   return 0;
}
