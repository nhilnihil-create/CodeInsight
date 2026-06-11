#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
   int n;
   cin>>n;

   vector<pair<int,int>> v;
   rep(i,n){
       int a,b;
       cin>>a>>b;
       v.push_back({b,a});
   }

   sort(all(v));
   int s=0;
   rep(i,n){
       if(s+v[i].second>v[i].first){
           //cout<<i<<" "<<s<<endl;
           cout<<"No"<<endl;
           return 0;
       }
       s+=v[i].second;
   }

   cout<<"Yes"<<endl;
}