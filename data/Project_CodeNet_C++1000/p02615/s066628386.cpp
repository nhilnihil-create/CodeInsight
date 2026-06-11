#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 
typedef long long ll;
int n;
int main(){
    cin >> n;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<ll>());
    ll ans=0;
    for(int i=0; i<n-1; i++){
        if(i==0){ans+=a[0]; continue;}
        int a_index=i/2+i%2;
        ans += a[a_index];  
    }
    cout << ans << "\n";
}