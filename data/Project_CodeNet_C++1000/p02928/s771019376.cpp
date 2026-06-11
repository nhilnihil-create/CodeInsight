#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int num=1e9+7;
int main(){
    ll n,k;
    cin >> n >> k;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    ll ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i]>a[j]&&i<j)ans+=k*(k+1)/2;
            ans%=num;
            if(a[i]>a[j]&&i>j)ans+=k*(k-1)/2;
            ans%=num;
        }
    }
    cout << ans << endl;
}