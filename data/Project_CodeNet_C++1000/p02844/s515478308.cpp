#include <bits/stdc++.h>
using namespace std;

#define print cout <<
#define printl(s) cout << s << endl;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

const ll modseed = pow(10,9) + 7;

template <typename T>
vector<T> getValues(int num){
    vector<T> values(num);
    for(int i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

string getindex(string s, char tg){
  
}

bool find(string s, int tg){
  int d1 = tg /100;
  
}

int main(){
  int N;
  string S;
  cin >> N >> S;
  int ans = 0;
  for(int i=0;i<1000;i++){
    int c[3] = {i/100,(i/10)%10, i%10};
    int f = 0;
    for(int j=0;j<N;j++){
      if(S[j] == ('0' + c[f])){
        f++;
      }
      if(f == 3) break;
    }
    if(f==3){
      ans++;
    }
  }
    printl(ans);
  
}
