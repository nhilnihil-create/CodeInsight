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
     int n,h; cin >> n >> h;
     int a[n];
     int cnt;
     scanArray(a,n);
     for(int i=0; i<n; i++){
        if(a[i]>=h){
            cnt++;
        }
     }
     cout << cnt << endl;
    return 0;
}
