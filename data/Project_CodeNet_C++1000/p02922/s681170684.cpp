/*
      author  : nishi5451
      created : 15.08.2020 12:16:59
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int a,b;
    cin >> a >> b;
    if(b==1){
        cout << 0 << endl;
        return 0;
    }
    int now = a;
    int count = 1;
    while(now < b){
        count++;
        now += a-1;
    }
    cout << count << endl;
    return 0;
}