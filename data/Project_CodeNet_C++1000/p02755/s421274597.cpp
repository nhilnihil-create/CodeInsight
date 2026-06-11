/*
      author  : nishi5451
      created : 14.08.2020 21:19:00
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int a,b;
    cin >> a >> b;
    for(int i=1; i<100000; i++){
        if(a==i*8/100 && b==i*10/100){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}