  #include <bits/stdc++.h>
  #define REP(i,n) for (int i = 0; i <(n); ++i)
  #define ALL(v) v.begin(), v.end()
  using namespace std;
  using ll = long long;
  using P = pair<int,int>;
  static const double PI = acos(-1);



  int main(){
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> point(n);

    REP(i,q){
      int a;
      cin >> a;
      --a;
      ++point[a];
    }

    REP(i,n){
      if(k - q + point[i] > 0) cout << "Yes" << endl;
      else cout << "No" << endl;
    }

    return 0;
  }