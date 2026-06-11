#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

int main(){
  int N;
  cin >> N ;
  int num = 0;
  for(int i=1;i<=N;i++){
    int a; cin >> a;
    if(a==num+1) num++;
  }
  if(num==0) cout << -1 << endl;
  else cout << N-num << endl;
}