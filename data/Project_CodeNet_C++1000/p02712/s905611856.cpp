#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n,sol=0;
    cin >> n;
    for (int i=1;i<=n;i++) {
        if (i%3>0 && i%5>0) sol+=i;
    }
    cout << sol;

}

