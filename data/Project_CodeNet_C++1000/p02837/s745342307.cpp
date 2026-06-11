#include <bits/stdc++.h>
using namespace std;

#define printl(s) cout << s << endl;
#define print(s) cout << s << endl; return 0;
#define yes cout << "Yes" << endl; return 0;
#define no cout << "No" << endl; return 0;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,n) for (int i = 1; i < (n)+1; ++i)
#define birep(i,n) for (int i = 0; i < (1<<(n));i++)
using ll = long long;
using pint = pair<int, int>;

const ll modseed = pow(10,9) + 7;

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
vector<vector<pint>> v;

bool judge(int bit){
  rep(i,N){
    if(!(bit & (1 << i))) continue;
    for(pint xy : v.at(i)){
      int x = xy.first;
      int y = xy.second;

      if(y==1 && !(bit &(1<<x))) return false;
      if(y==0 && (bit &(1<<x))) return false;
    }
  }
  return true;
}

int main(){
  cin >> N;
  v.resize(N);
  rep(i,N){
    int A; cin >> A;
    v.at(i).resize(A);
    rep(j,A){
      cin >> v.at(i).at(j).first >> v.at(i).at(j).second;
      --v.at(i).at(j).first;
    }
  }
  cnt=0;
  birep(bit,N){
    if(judge(bit)){
      int count = 0;
      rep(i,N){
        if(bit & (1 << i)) ++count;
      }
      cnt = max(cnt,count);
    }
  }
  printl(cnt);
}
