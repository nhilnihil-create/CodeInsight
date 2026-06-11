/*
      author : nishi5451
      created: 11.08.2020 21:52:00
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int p,q,r;
    cin >> p >> q >> r;
    cout << p+q+r-max(max(p,q),r) << endl;
    return 0;
}