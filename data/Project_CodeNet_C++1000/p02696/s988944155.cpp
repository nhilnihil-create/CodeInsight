#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define mm(arr) memset(arr, 0, sizeof(arr))
#define scanArray(a,n) for(int i = 0; i < n; i++){cin >> a[i];}
#define pb push_back
#define PI 3.141592653589793
#define MOD 1000000007

using namespace std;
int main(){
    FAST
    ll a,b,n; cin >> a >> b >> n;
    ll res1,res2;
    if(b>=n){
        res1= floor((double)a*n/b) - ((double)a*(floor(n/b)));
        res2= floor((double)a*(n-1)/b) - ((double)a*(floor((n-1)/b)));
        cout << max(res1,res2) << endl;
        return 0;
    }
    if(b<n){
        res1= floor((double)a*b/b) - ((double)a*(floor(b/b)));
        res2= floor((double)a*(b-1)/b) - ((double)a*(floor((b-1)/b)));
        cout << max(res1,res2) << endl;
        return 0;
    }



    return 0;
}
