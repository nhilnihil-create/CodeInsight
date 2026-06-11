#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<cmath>
#define rep(i, n) for(int i=0; i<n; i++)
#define rrep(i, n) for(int i=n-1; i>=0; i--)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define rFOR(i, a, b) for(int i=b-1; i>=a; i--)
#define MAX 100
using namespace std;
typedef long long ll;

int main(void){
  while(true){
    int n, m, p; cin >> n >> m >> p;
    if(n+m+p==0)  break;
    int x[MAX], sum=0;
    rep(i, n) {
      cin >> x[i];
      sum += x[i]*100;
    }
    sum = sum * (100-p) /100;
    if(x[m-1]==0) cout << 0 << endl;
    else   {
      sum /= x[m-1];
      cout << sum << endl;
    }
  }
  return 0;
}

