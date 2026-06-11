#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using Graph = vector<vector<int>>;
const int INF = 998244353;
ll func(ll a,ll b){//aのb乗を返す
    ll res = 1;
    for(int i = 0;i<b;i++){
        res *= a;
        res = res%INF;
    }
    return res;

}
using Graph = vector<vector<int>>;
/*
*/


int main() {
   ll N;
  cin >> N;
   vector<ll> D(N);
   rep(i,N){
       cin >> D[i];
   }
  
   if(D[0] != 0) cout << 0 << endl;
   else{
     sort(D.begin(),D.end());
     D.push_back(-1);

     vector<pair<ll,ll>> p;//(Di,Diの点の個数)のペア配列
     ll c = 1;//Diの個数
     for(int i = 0;i<N;i++){
       if(D[i] == D[i+1]) c++;
       else if(D[i] != D[i+1]){
           p.push_back(make_pair(D[i],c));
           c = 1;
       }
     }
     /*for(int i = 0;i<p.size();i++){
         cout << p[i].first << " " << p[i].second << endl;
     }*/
  
     bool flag = true;//隣あうp[i].firstの差が2以上ならfalse
     for(int i = 0;i<p.size()-1;i++){
         if(p[i+1].first - p[i].first >= 2){
             flag = false;
             break;
         }  
     }
     if(p[0].second >= 2) flag = false;
     
     if(flag){
       ll ans = 1;
       for(int i = 0;i<p.size()-1;i++){
           ans *= func(p[i].second,p[i+1].second);
           ans = ans%INF;
       }
       cout << ans << endl;
     }
     else cout << 0 << endl;
   }
}