/*
      author : nishi5451
      created: 12.08.2020 11:39:54
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int h1,m1,h2,m2,k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    int ans = (h2-h1-1)*60+(m2+60-m1);
    cout << ans-k << endl;
    return 0;
}
