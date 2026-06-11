#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define set_zero(a) memset(a,0,sizeof(a));
#define ll long long
#define PI 2 * acos(0.0)
#define MAX 1000000000
#define INF 1000000 
#define M 1000000007
using namespace std;
vector<string> v1;
void permute(string str) 
{ 
    do { 
      v1.push_back(str);
    } while (next_permutation(str.begin(), str.end())); 
}
long double distance(ll a, ll b ,ll c ,ll d){
   long long int a1 = pow(abs(b-a),2);
   long long int a2 = pow(abs(d-c),2);
   long double dis = (long double) a1 + (long double) a2;
   long double y = sqrt(dis);
   return y;
}
int main(){
   ll n;
   cin>>n;
   vector< pair < ll,ll > > v;
   v.push_back({0,0});
   for(ll i = 1;i<=n;i++){
      ll x,y;
      cin>>x>>y;
      v.push_back({x,y});
   }
   string s;
   for(ll i = 1;i<=n;i++){
      string d = to_string(i);
      s.push_back(d[0]);
   }
   permute(s);
   long double ans1 = 0;
   long double cnt = 0;
      for(ll i = 0;i<v1.size();i++){
          string h = v1[i];
          ll k = h[0] - '0';
          long double sum = 0;
          for(ll j = 1;j<h.length();j++){
             ll u  = h[j] - '0';
             ll a = v[k].first;
             ll b = v[u].first;
             ll c = v[k].second;
             ll d = v[u].second;
             sum += distance(a,b,c,d);
             k = h[j] - '0';
          }
          ans1 += sum;
          cnt++;
      }
   long double main_ans = ans1/cnt ;
   cout<<fixed<<setprecision(10)<<main_ans<<endl;
   return 0;
}