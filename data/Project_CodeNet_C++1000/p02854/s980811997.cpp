#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    long long n, sum = 0;
    cin >> n;
    vector<long long>a(n),sf(n),sb(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum += a[i];
        sf[i] = sum;
    }
    sum = 0;
    for(int i=n-1; i>=0; i--){
        sum += a[i];
        sb[i] = sum;
    }
    long long ans = sf[n-1];
    for(int i=0; i<n-1; i++){
        int j = i+1;
        ans = min(abs(sf[i]-sb[j]),ans);
    }
    cout << ans << endl;
    return 0;
}