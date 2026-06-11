#include <bits/stdc++.h>
using namespace std;

#define printl(s) cout << s << endl;
#define print(s) cout << s << endl; return 0;
#define yes cout << "Yes" << endl; return 0;
#define no cout << "No" << endl; return 0;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,n) for (int i = 1; i < (n)+1; ++i)
#define birep(i,n) for (int i = 0; i < (1<<(n));i++)
#define isOne(bit,i) (bit & (1 << i))
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

bool judge(int bit, vector<vector<pint>> shougens){
  rep(i,N){
    if(!isOne(bit,i)){
      continue;
    }
    for(auto xy : shougens.at(i)){
      int x = xy.first;
      int y = xy.second;
      if(y==1 && !isOne(bit,x)) return false;
      if(y==0 && isOne(bit,x)) return false;
    }
  }
  return true;
}

int main(){
  cin >> N;
  vector<vector<pint>> shougens(N);
  rep(i,N){
    int A; cin >> A;
    shougens.at(i).resize(A);
    rep(j,A){
      cin >> shougens.at(i).at(j).first >> shougens.at(i).at(j).second;
      shougens.at(i).at(j).first--;
    }
  }
  cnt = 0;
  birep(i,N){
    if(judge(i,shougens)){
      bitset<15> b(i);
      int res = b.count();
      cnt = max(res,cnt);
    }
  }
  print(cnt);
}
