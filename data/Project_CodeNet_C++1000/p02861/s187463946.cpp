#include <bits/stdc++.h>
using namespace std;
#define rep(i,end) for(ll i = 0; i < end ; i++ )
typedef long long ll;
typedef vector<ll> vi;

double norm(ll x1, ll x2, ll y1, ll y2){
  return pow(pow(x1-x2,2) + pow(y1-y2, 2),0.5);
}

long long kaijou(int x){
  ll ideal = 1;
  rep(i, x){
    ideal *= x-i;
  }
  return ideal;
}

double sum(vector<double> vec){
  return accumulate(vec.begin(), vec.end(), 0);
}

int main() {
  double ideal = 0.0;
  ll N;
  cin >> N;
  vector<vector<ll> > vec(N, vector<ll>(2));
  rep(i, N) cin >> vec[i][0] >> vec[i][1];
  rep(i, N-1){
    for (int j =i+1; j < N; j++){
      ideal += norm(vec[i][0], vec[j][0], vec[i][1], vec[j][1]);
    }
  }
  ideal *= 2.0;
  double M;
  M = N;
  ideal /= M;
  cout << fixed << setprecision(15) << ideal << endl;
}