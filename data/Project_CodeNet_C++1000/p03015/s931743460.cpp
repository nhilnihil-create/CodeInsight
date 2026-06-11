#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  string s;
  cin >> s;
  int64_t p=1000000007;
  int n=s.size();
  vector<int64_t> k(n,0);
  vector<int64_t> w(n,0);
  w[0]=1;
  k[0]=2;
  rep(i,n-1){
    int64_t y=i+1;
    if(s[y]=='0'){
      w[y]=(w[i]*3)%p;
      k[y]=k[i];
    }
    else{
      w[y]=(w[i]*3+k[i])%p;
      k[y]=(k[i]*2)%p;
    }
  }
  cout << (k[n-1]+w[n-1])%p << endl;
}
