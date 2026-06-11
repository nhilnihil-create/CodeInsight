#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<pair<int, int>> res;
  
  sort(a.begin(), a.end());
  int smallest = a[0];
  int biggest = a[a.size() - 1];
  for (int i = 1; i < n - 1; i++){
    if (a[i] < 0){
      res.pb({biggest, a[i]});
      biggest -= a[i];
    }else{
      res.pb({smallest, a[i]});
      smallest -= a[i];
    }
  }
  cout << biggest - smallest << endl;
  rep(i, (int)res.size()) cout << res[i].first << ' ' << res[i].second << endl;
  cout << biggest << ' ' << smallest << endl;
}