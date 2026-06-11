/*
      author  : nishi5451
      created : 15.08.2020 11:25:10
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,d;
    cin >> n >> d;
    if(n%(2*d+1)==0)   cout << n/(2*d+1) << endl;
    else cout << n/(2*d+1) + 1 << endl;
    return 0;
}