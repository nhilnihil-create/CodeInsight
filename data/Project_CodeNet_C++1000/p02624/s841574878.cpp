/*
      author : Nishikawa
      created: 06.08.2020 14:01:46
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;

ll SUM(ll n){
    return n*(n+1)/2;
}

//Xまでの正の約数の総和を数えるプログラム
int main(){
    ll X; 
    cin >> X;
   // vector<int> vec(X+1,0);
   ll sum=0;
   for(ll i=1; i<=X; i++)
    sum+=SUM(X/i)*i;
        cout << sum << endl;
    return 0;
}