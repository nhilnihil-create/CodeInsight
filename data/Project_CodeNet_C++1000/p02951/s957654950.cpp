/*
      author : nishi5451
      created: 11.08.2020 22:15:30
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int a,b,c;
    cin >> a >> b >> c;
    cout << max(c-(a-b),0) << endl;
    return 0;
}