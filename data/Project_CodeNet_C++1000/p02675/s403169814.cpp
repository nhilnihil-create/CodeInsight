/*
      author : nishi5451
      created: 11.08.2020 23:17:00
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    n%=10;
    switch(n){
        case 3: cout << "bon" << endl; break;
        case 0:
        case 1:
        case 6:
        case 8: cout << "pon" << endl; break;
        default : cout << "hon" << endl; break;
    }
    return 0;
}
