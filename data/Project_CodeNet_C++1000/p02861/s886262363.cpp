#include <bits/stdc++.h>

using namespace std;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long




int main() {
  int N; cin >> N;
  int x[N];
  int y[N];
  double sum=0.0;
  ll count=0;
  vector<int> v;
  rep(i,N){
    cin >> x[i] >> y[i];
    v.push_back(i);
  }

  while(1){
    rep(i,v.size()-1){
      double xdist = x[v[i]] - x[v[i+1]];
      //cout <<"xdist:"<< xdist << endl;
      double ydist = y[v[i]] - y[v[i+1]];
      //cout <<"ydist:"<< ydist << endl;
      sum += sqrt(xdist*xdist + ydist*ydist);
      //cout <<"sum:" << sum << "\n" << endl;
    }
    count++;
    if(!next_permutation(v.begin(),v.end())) break;
  }
  //cout << "sum:" << sum <<", count:" << count << endl;
  cout << setprecision(12) << sum/count << endl;

}