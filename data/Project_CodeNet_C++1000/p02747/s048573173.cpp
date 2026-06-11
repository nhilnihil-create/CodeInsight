#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define All(a) a.begin(),a.end()
#define INF 1000000007
const int MOD = 1000000007;
//accumulate(vec.begin(), vec.end(), 0)

int gcd(int x,int y){
  if(x%y==0) return y;
  else return gcd(y,x%y);
}

int main(){
  string s;
  cin >> s;
  for(int i=0;i<s.size();i+=2){
    if(!(s[i]=='h' && s[i+1]=='i')){
      cout<< "No" <<endl;
      return 0;
    }
  }
  cout<< "Yes" <<endl;
}
