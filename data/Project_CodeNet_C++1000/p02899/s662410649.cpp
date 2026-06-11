#include <iostream>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <algorithm>
#include <bits/stdc++.h>
#define MOD 1000000000000000000
#define ll long long
#define mm(arr) memset(arr, 1, sizeof(arr))
#define scanArray(a,n) for(ll i = 0; i < n; i++){cin >> a[i];}
using namespace std;
void prime(ll n1);
int main(){
    FAST
    int n; cin >> n;
    pair<int, int>a[n];
    for(int i =0; i<n; i++){
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a,a+n);
    for(int i=0; i<n; i++){
        cout << a[i].second << " ";
    }
    cout << endl;



    return 0;
}
