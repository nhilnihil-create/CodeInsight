#include <iostream>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <algorithm>
#include <bits/stdc++.h>
#define MOD 1000000000
#define ll long long
#define mm(arr) memset(arr, 0, sizeof(arr))
#define scanArray(a,n) for(ll i = 0; i < n; i++){cin >> a[i];}
#define PI 3.141592653589793
using namespace std;
int main(){
    FAST
    int n; cin >> n;
    int a[n-1];
    int boss[n+1];
    mm(boss);
    for(int i=1; i<n; i++){
        cin >> a[i];
        boss[a[i]]++;
    }
    for(int i=1; i<=n; i++){
        cout << boss[i]<< endl;
    }
    return 0;





}
