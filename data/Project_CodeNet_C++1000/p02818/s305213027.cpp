/*
      author  : nishi5451
      created : 15.08.2020 13:34:37
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    ll a,b,k;
    cin >> a >> b >> k;
    if(a>=k){
        cout << a-k << " " << b << endl; 
    }
    else{
        cout << 0 << " " << max((ll)0,b-(k-a)) << endl;
    }
    return 0;
}