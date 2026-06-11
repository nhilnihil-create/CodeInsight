#include <bits/stdc++.h>
using namespace std;

int main(){
  constexpr int Nmax= 200'000;
  constexpr int Nbit= Nmax+ 1;
  int N;
  cin >> N;

  vector<int> mod2(N+1);
  for(int d=1; d<= N; d++){
    cin >> mod2.at(d);
  }

  bitset<Nbit> bs;
  for(int d=N; d>=1; d--){
    int cnt_mul= 0;
    for(int m= 2*d; m<= N; m+=d){
      if(bs.test(m)){
        cnt_mul++;
      }
    }
    cnt_mul %= 2;

    if(mod2.at(d)==0){
      if(cnt_mul==1){ bs.set(d); }
    }
    else{
      if(cnt_mul==0){ bs.set(d); }
    }
  }

  cout << bs.count() << endl;
  for(int d=1; d<=N; d++){
    if(bs.test(d)){
      cout << d <<" ";
    }
  }
}