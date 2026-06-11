  #include <bits/stdc++.h>
  #define REP(i,n) for (int i = 0; i <(n); ++i)
  #define ALL(v) v.begin(), v.end()
  using namespace std;
  using ll = long long;
  using P = pair<int,int>;
  static const double PI = acos(-1);



  int main(){
    int n;
    cin >> n;
    vector<double> a(n);
    REP(i,n){
      int x;
      cin >> x;
      a[i] = 100000000/x;
    }

    double sum = 0;
    REP(i,n) sum += a[i];

    double ans = 100000000/sum;
    //ans *= 1000;

    cout << fixed << setprecision(12) << ans << endl;

    return 0;
  }