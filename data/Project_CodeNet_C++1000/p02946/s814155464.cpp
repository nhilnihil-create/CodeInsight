/*
      author  : nishi5451
      created : 15.08.2020 12:04:08
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,x;
    cin >> n >> x;
    int ans = 0;
    for(int i=x-n+1; i<=x+n-1; i++){
        cout << i << endl;
    }

    return 0;
}