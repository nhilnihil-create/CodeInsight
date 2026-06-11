/*
      author : nishi5451
      created: 12.08.2020 14:56:20
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int m1,d1,m2,d2;
    cin >> m1 >> d1 >> m2 >> d2;
    if(m1+1==m2 && d2==1)
        cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}