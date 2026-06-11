#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  sort(all(a));
  int maxValue = a[n-1];//配列の最大値を取得
  
  vector<bool> b(maxValue+1,1);//カウントするかどうかのbool配列
  
  map<int,int> c;//重複をチェックするためのmap
  rep(i,n) c[a[i]]++;
  
  rep(i,n){
    int now = a[i];
    if(b[now] == 0) continue;//カウントなしであればスルー
    for(int j=now*2;j<=maxValue;j+=now){//後続の約数をカウントなしにしていく
      b[j] = 0;
    }
  }
  
  int ans = 0;//集計開始
  rep(i,n){
    int now = a[i];
    if(c[now]>1) continue;//重複していればスルー
    ans += b[now];
  }
  cout << ans << endl;
}
