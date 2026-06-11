#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;

int main(){
  int a, b;
  cin >> a >> b;
  int M=10*b;
  int cnt=0;
  rep(i,10){
    if(floor((M+0.0)*0.08)==a){
      cout << M;
      return 0;
    }
    M++;
  }
  cout << -1;
  return 0;
}