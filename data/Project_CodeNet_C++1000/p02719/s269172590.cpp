#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,k;
    cin >> n >> k;
    long long ans=min(n%k,k-n%k);
    cout << ans << endl;
    return 0;    
}