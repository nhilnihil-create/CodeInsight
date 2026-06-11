#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll n;
    cin >> n;
    ll a[n];
    ll count=0;
    for(ll i=0;i<n;i++){
        cin >> a[i];
        count+=a[i];
        a[i]*=2;
    }
    ll b[n];
    b[0]=count;
    for(ll i=1;i<n;i+=2){
        b[0]-=a[i];
    }
    for(ll i=0;i<n-1;i++){
        b[i+1]=a[i]-b[i];
    }
    for(ll i=0;i<n;i++) cout << b[i] << " ";
    cout << endl;
}
