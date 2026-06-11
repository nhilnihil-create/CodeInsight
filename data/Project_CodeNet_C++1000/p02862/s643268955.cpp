#include<bits/stdc++.h>

//短縮
#define rep(i,n) for(int i=0;i<(n);++i)
//sort()用
#define all(v) v.begin(), v.end()

#define PB(N) push_back(N)

#define MOD 1000000007

using namespace std;

using Graph = vector<vector<int>>;

//mod,mでのaの逆元a^(-1)を計算する
long long modinv(long long a, long long m){
  long long b = m, u=1,v=0;
  while(b){
    long long t=a/b;
    a -= t*b; swap(a,b);
    u -= t*v; swap(u,v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}

long long kumiawase(long long a, long long b){
  long long answer=1;
  for(long long i=0;i<a+b;i++){
    answer *= (a%MOD+b%MOD-i%MOD)%MOD;
    answer=answer%MOD;
    if(i < a){
      answer = ((answer%MOD)*modinv(i+1,MOD))%MOD;
      answer=answer%MOD;
    }
    if(i < b){
      answer = ((answer%MOD)*modinv(i+1,MOD))%MOD;
      answer=answer%MOD;
    }
  }
  //aとb
  return answer;
}

int main(){
  int X,Y;
  cin >> X >> Y;
  long long a=(2*Y-X)/3;
  long long b=(2*X-Y)/3;
  //(a+b)%2==(X+Y)%2はいらない?
  if((2*Y-X)%3==0&&(2*X-Y)%3==0){
    if(a<0||b<0) cout << 0;
    else cout << kumiawase(a, b) << endl;
  }
  else{
    cout << 0;
  }

  return 0;
}
