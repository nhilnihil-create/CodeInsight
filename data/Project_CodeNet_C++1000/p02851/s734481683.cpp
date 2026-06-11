
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;



int main(){
   int n, k;
   cin >> n >> k;
   vector<ll> a(n);
   rep(i,n){
       cin >> a.at(i);
       a[i]--; //各aiをあらかじめ1引いておくと「部分和の余りが0に等しい」に帰着できる
   }

   //累積和のmod kを格納する
   vector<ll> sum(n+1);
   rep(i,n){
       sum.at(i+1) = (sum.at(i) + a.at(i))%k;
    }

    //mapを使って累積和の剰余項ごとの個数を管理
    map<ll,int> C;
    queue<int> q;
    ll ans=0LL;

    rep(i,n+1){
        ans += C[sum.at(i)];
        C[sum[i]]++;    //余りがsum[i]になるものの個数を1増やす
        q.push(sum.at(i));

        //長さk以上隔てたペアはカウントしないようにする
        if(q.size()==k){
            C[q.front()]--;
            q.pop(); //先頭の要素を削除する
        }
    }
    cout << ans << endl;


}