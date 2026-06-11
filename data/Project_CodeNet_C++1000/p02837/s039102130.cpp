#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define printl(s) cout << s << endl;
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
int N,ans;

bool check(vector<pii> evi, int i){
  for(int j=0;j<(int)evi.size();j++){
    if( (i&(1<<evi[j].first)) && (evi[j].second==0)) return false;
    if( !(i&(1<<evi[j].first)) && (evi[j].second==1)) return false;  
  }
  return true;
}

int main(){
  ans = 0;
  cin >> N;
  vector<vector<pii>> evi(N);
  for(int i=0;i<N;i++){
    int A;
    cin >> A;
    evi[i].resize(A);
    rep(j,A){
      int x,y;
      cin >>x>>y;
      evi[i][j] = make_pair(x-1,y);
    }
  }
  for(int i=0;i<(1<<N);i++){
    bool flg = true;
    for(int j=0;j<N;j++){
      if(!(i &(1<<j))) continue;
      if(!check(evi[j],i)){
        flg = false;
        break;
      }
    }
    if(flg){
      bitset<15> s(i);
      int num = s.count();
      ans = max(ans,num);
    }
  }

  printl(ans);
}
