#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<string>
#include<sstream>
#include<cmath>
#include<numeric>
using namespace std;


int main(){

  int n, m;
  while(cin >> n >> m){
    if( n == 0 && m == 0 ) break;

    vector<int> a(n);
    vector<int> b(m);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];

    int asum = accumulate(a.begin(), a.end(), 0);
    int bsum = accumulate(b.begin(), b.end(), 0);

    int aans = 10000;
    int bans = 10000;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if( asum - bsum == (a[i] - b[j]) * 2 ){
          if( aans + bans > a[i] + b[j] ){
            aans = a[i];
            bans = b[j];
          }
        }
      }
    }
    if( aans == 10000 && bans == 10000 ) cout << -1 << endl;
    else cout << aans << " " << bans << endl;

  }

  return 0;
}








// EOF