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

int main(){
    int N;
    string S;
    cin >> N >> S;
    int ans = 0; 
    rep(i,N-2){
      if((S.at(i)=='A') && (S.at(i+1)=='B') && (S.at(i+2)=='C')){
        ans++;
      }
    }
    printl(ans);
}
