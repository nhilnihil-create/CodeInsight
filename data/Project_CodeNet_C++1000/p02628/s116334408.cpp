#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a,a+n);
    int sum=accumulate(a,a+k,0);
    cout << sum <<endl;
}

int main(){
   // int t;  cin >> t;   while(t--)
    solve();

    return 0;
}
