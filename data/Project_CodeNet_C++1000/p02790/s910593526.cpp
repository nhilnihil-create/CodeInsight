/*
      author  : nishi5451
      created : 15.08.2020 13:47:48
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int a,b;
    cin >> a >> b;
    if(a>b){
        rep(i,a){
            cout << b ;
        }
        cout << endl;
    }
    else if(b>a){
        rep(i,b){
            cout << a;
        }
        cout << endl;
    }
    else {
        rep(i,min(a,b)){
            cout << a;
        }
        cout << endl;
    }
    return 0;
}