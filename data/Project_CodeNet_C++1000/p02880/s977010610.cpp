#include <bits/stdc++.h>
using namespace std;

#define print cout <<
#define printl(s) cout << s << endl;
#define prif(s) cout << s << endl; return 0;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,n) for (int i = 1; i < (n)+1; ++i)
using ll = long long;

const ll modseed = pow(10,9) + 7;

template <typename T>
vector<T> getValues(ll num){
    vector<T> values(num);
    for(ll i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

const string yes = "Yes";
const string no = "No";

string S;
int N, cnt;

int main(){
  cin >> N;
  rep2(i, 9){
    rep2(j,9){
      if(i*j==N){
        prif(yes);
      }
      }
    }
  prif(no);
}
