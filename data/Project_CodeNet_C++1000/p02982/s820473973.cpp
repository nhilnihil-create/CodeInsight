#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define printl(s) cout << s << endl;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using vvi = vector<vector<int>>;

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
ll N,D,ans;

double dist(vector<int> p1, vector<int> p2, int dim){
  int res = 0;
  rep(i,dim){
    res+=pow(p1[i]-p2[i],2);
  }
  return sqrt(res);
}

int main(){
  ans = 0;
  cin >> N>>D;
  vvi points(N,vector<int>(D));
  rep(i,N){
    points[i] = getVector<int>(D);
  }
  rep(i,N){
    for(int j=i+1;j<N;j++){
      double dis = dist(points[i],points[j],D);
      if(floor(dis)==dis){
        ans++;
      } 
    }
  }
  printl(ans);
}
