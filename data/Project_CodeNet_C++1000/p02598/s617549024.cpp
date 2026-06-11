#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n,k,ub = 0,lb = 0;
  cin >> n >> k;
  vector<int>a(n);
  rep(i,0,n){cin >> a[i];ub = max(ub,a[i]);}
  ub++;
  int mid = (lb+ub)/2; //ここで二分
  while(ub-lb != 1){
    int cnt = 0;
    rep(i,0,n){
      cnt += a[i]/mid;
      if(a[i]%mid == 0) cnt--;
    }
    //cout << cnt << " ";
    if(cnt > k){ //src以下（大事！！！！）になる最後の要素
      lb = mid; 
      mid = (lb+ub)/2;
    }
    else{
      ub = mid;
      mid = (lb+ub)/2;
    }
    //cout << mid << endl;
  }
  cout << ub << endl;
}