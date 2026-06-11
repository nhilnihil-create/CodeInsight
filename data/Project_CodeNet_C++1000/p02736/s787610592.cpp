#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[1000009];
main(){
    int n;
    cin >> n;
    int o = 0;
    for(int i = 1; i <= n; i++){
       char c;
       cin >> c;
       a[i] = c - '1';
       if(a[i] == 1) o = 1;

    }
    if(!o){
        for(int i = 1 ;i <= n; i++){
            a[i] /= 2;
        }
    }
    int x = 0;
    for(int i = 0; i < n; i++){
        if((i & (n - 1 - i)) == 0) x ^= (a[i+1]&1);
    }
    if(!o) cout << 2*x << endl;
    else cout << x << endl;
}
