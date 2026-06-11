#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define mm(arr) memset(arr, 1, sizeof(arr))
#define scanArray(a,n) for(int i = 0; i < n; i++){cin >> a[i];}
#define pb push_back
#define PI 3.141592653589793
#define MOD 1000000007
using namespace std;
int main(){
    FAST
    int n,m; cin >> n >> m;
    int h[n], a[m],b[m];
    for(int i=0;i<n;i++){
        cin >> h[i];
    }
    int good[n];
    for(int i = 0; i < n; i++){
        good[i] = 1;
    }
    for(int i=0; i<m; i++){
        cin >> a[i] >> b[i];
        if(h[a[i] - 1] <= h[b[i] - 1]){
                good[a[i]-1] = 0;
        }
        if(h[b[i] - 1] <= h[a[i] - 1]){
            good[b[i] - 1] = 0;
        }
    }
    int sum=0;
    for(int i=0; i<n; i++){
        sum += good[i];
    }
    cout << sum << endl;


    return 0;
}