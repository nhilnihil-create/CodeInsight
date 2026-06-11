/*
      author : nishi5451
      created: 11.08.2020 23:19:15
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int tmp;
    rep(i,5) {
        cin >> tmp;
        if(tmp==0){
            cout << i+1 << endl;
            return 0;
        }
    }
    return 0;
}