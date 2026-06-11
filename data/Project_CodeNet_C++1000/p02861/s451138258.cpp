#include <bits/stdc++.h>
using namespace std;

#define printl(s) cout << s << endl;
#define print(s) cout << s << endl; return 0;
#define printFix(n,i) cout << fixed << setprecision(i) << n << endl; return 0;
#define yes cout << "Yes" << endl; return 0;
#define no cout << "No" << endl; return 0;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,n) for (int i = 1; i < (n)+1; ++i)
#define bitrep(i,n) for (int i = 0; i < (1<<(n));i++)
#define isOne(bit,i) (bit & (1 << i))
using ll = long long;
using pii = pair<int, int>;

const ll modseed = pow(10,9) + 7;
const int INF = 100'000'000;

template <typename T>
vector<T> getValues(ll num){
    vector<T> values(num);
    for(ll i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

string S;
int N,cnt;

double calcDist(pii p1, pii p2){
  double x = (p1.first - p2.first) * (p1.first - p2.first);
  double y = (p1.second - p2.second) * (p1.second - p2.second);
  return sqrt(x+y);
}

int main(){
  cin >> N;
  vector<vector<double>> dists(N,vector<double>(N));
  vector<pii> poss(N);
  rep(i,N){
    int X, Y;
    cin >> X >> Y;
    poss.at(i) = pii(X,Y);
  }
  rep(i,N){
    rep(j,N){
      dists.at(i).at(j) = calcDist(poss.at(i),poss.at(j));
    }
  }
  vector<int> cases(N);
  rep(i,N) cases.at(i) = i;
  double total = 0;
  do{
    for(int i=0;i<N-1;i++){
      total += dists.at(cases.at(i)).at(cases.at(i+1));
    }
  }while(next_permutation(cases.begin(),cases.end()));
  double divT = 1;
  for(int i=2;i<=N;i++){
    divT *= i;
  }
  double res = total / divT;
  printFix(res,10);

}
