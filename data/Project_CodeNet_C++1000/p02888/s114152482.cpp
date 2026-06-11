#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define INF 2147483647
#include<bits/stdc++.h>

int main() {
  int n; cin >> n;
  
  /*
  後で使うlower_boundは、探索している値が見つからないときは、
  その探索範囲の最後のイテレータを返す関数。
  そのため、探索している値が見つからなかったときに備えて、
  配列の最後に非常に大きな値を入れておくことにする。
  */
  vector<int>L(n+1);
  rep(i,n) cin >> L[i];
  L[n] = INF; //配列の最後に大きな値を入れておく（上述）。
  sort(L.begin(), L.end());
  int ans = 0;
  for (int i=0; i<=n-3; i++){
    for (int j=i+1; j<=n-2; j++){
      int border = L[i]+L[j];
      auto itr = lower_bound(L.begin(), L.end(), border);

      /*
      lower_boundの返り値が配列の最後（itr == L.end(）)のとき、
      このiとjの値のときは作れる三角形は存在しない。
      そのため、itr != L.end(）の場合のみ答えとなる個数を加算していく。
      */
      if (itr != L.end()){
        int index = itr - L.begin();
        ans += index-1-j;
      }
    }
  }
  cout << ans << endl;
}

