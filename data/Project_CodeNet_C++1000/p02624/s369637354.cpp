#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll int n,k,sum=0;
    cin >> n;
    for (int i=1; i<=n; i++){
        k=n/i;
        sum+=k*(k+1)/2*i;
    }
    cout << sum;
}