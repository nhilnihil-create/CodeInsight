#include <iostream>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <algorithm>
#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define l long
#define mm(arr) memset(arr, 0, sizeof(arr))
#define scanArray(a,n) for(int i = 0; i < n; i++){cin >> a[i]}
using namespace std;
int main(){
    FAST
    int n; cin >> n;
    int x, y;
    ll counter=0;
    for(int a=1; a<=n; a++){
        for(int b=1; b<=n; b++){
            for(int c=1; c<=n; c++){
                x=__gcd(a,b);
                y=__gcd(x,c);
                counter+=y;
            }
        }
    }
    cout << counter << endl;
    return 0;
}
