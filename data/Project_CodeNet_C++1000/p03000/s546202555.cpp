/*
      author  : nishi5451
      created : 15.08.2020 10:42:10
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,x;
    cin >> n >> x;
    int now = 0;
    for(int i=1; i<=n; i++){
        int l;
        cin >> l;
        if(now+l > x){
            cout << i << endl;
            return 0;
        }
        now += l;
    }
    cout << n+1 << endl;
    return 0;
}