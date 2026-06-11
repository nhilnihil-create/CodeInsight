#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    long long int ans   = 1000;
    long long int stock = 0;

    for(int i=0; i+1<n; i++){
        if(a[i] < a[i+1]){
            stock += ans / a[i];
            ans -= (ans / a[i]) * a[i];
        }
        if(a[i] > a[i+1]){
            ans += stock * a[i];
            stock = 0;
        }
    }
    ans += stock * a[n-1];
    cout << ans << endl;
    return 0;
}