#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define printl(s) cout << s << endl;
#define printFix(n,i) cout << fixed << setprecision(i) << n << endl; return 0;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using vvi = vector<vector<int>>;
using pii = pair<int,int>;

const ll modSeed = pow(10,9) + 7;
const int INF = 1'000'000'000;

template <typename T>
vector<T> getVector(ll num){
    vector<T> values(num);
    for(ll i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

string S;
ll N,ans;

int main(){
  ans = 0;
  cin >> N;
  vector<pii> points(N);
  vector<int> pass(N);
  rep(i,N){
    pass[i] = i;
  }
  rep(i,N){
    int x,y;
    cin >>x>>y;
    points[i] = make_pair(x,y);
  }
  double sum =0;
  double count=0;
  do{
    count++;
    for(int i=1;i<N;i++){
      double distX = points[pass[i]].first-points[pass[i-1]].first;
      double distY = points[pass[i]].second-points[pass[i-1]].second;
      sum += sqrt(distX*distX+distY*distY);
    }
  }while(next_permutation(pass.begin(),pass.end()));
  printFix(sum/count,10);
}
