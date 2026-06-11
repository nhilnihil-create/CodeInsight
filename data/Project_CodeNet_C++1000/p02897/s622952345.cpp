#include <iostream>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <algorithm>
#include <bits/stdc++.h>
#define MOD 1000000000000000000
#define ll long long
#define mm(arr) memset(arr, 1, sizeof(arr))
#define scanArray(a,n) for(ll i = 0; i < n; i++){cin >> a[i];}
using namespace std;
int main(){
    FAST
     double n; cin >> n;
     double cnt;
     for(int i=1; i<=n; i++){
        if(i%2!=0){
            cnt++;
        }
     }
     cout << cnt/n << endl;
    return 0;
}
