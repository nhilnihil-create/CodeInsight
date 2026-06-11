#include <bits/stdc++.h>
using namespace std;
#define int long long
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int charToInt(char c){
    char zero_num = '0';
    return (int)c - (int)zero_num;
}

vector< int > divisor(int n) {
  vector< int > ret;
  for(int i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

signed main(){
    int N; cin>>N;
    vec_int a(N+1); rep(i,N)cin>>a.at(i+1);

    vec_int b(N+1,0);

    vec_int pos;

    for(int i=N;i>0;i--){
        // i番目の場所にボールを入れるか判断する
        if (b.at(i)%2 == a.at(i)){
            //ボールを入れない
        }else{
            vec_int yakusuu = divisor(i);
            for(auto num : yakusuu){
                b.at(num) +=1;
            }
            pos.push_back(i);
        }
    }

    cout<<pos.size()<<endl;
    for(auto num : pos){
        cout<<num<<endl;
    }




    return 0;
}