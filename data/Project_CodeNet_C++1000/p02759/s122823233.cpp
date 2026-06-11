/*
      author : nishi5451
      created: 11.08.2020 23:06:34
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    if(n%2) cout << n/2+1 << endl;
    else cout << n/2 << endl;
    return 0;
}