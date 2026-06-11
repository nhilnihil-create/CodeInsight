#include <iostream>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <algorithm>
#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define mm(arr) memset(arr, 1, sizeof(arr))
#define scanArray(a,n) for(int i = 0; i < n; i++){cin >> a[i];}
using namespace std;

int main(){
    FAST
    int k; cin >> k;
    int cnt=0, mx=0;
    bool ok=0;

    for(int a=1; a<=k; a++){
        for(int b=1;b<=k; b++){
            for(int c=1; c<=k;c++){
                        int ans =__gcd(a,b);
                        cnt+=__gcd(ans,c);

            }
        }
    }
    cout << cnt << endl;



    return 0;
}
