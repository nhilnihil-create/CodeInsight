#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int r,g,b,k;
    cin>>r>>g>>b>>k;
    while(g<=r && k) k--,g*=2;
    while(b<=g && k) k--,b*=2;
    if(b>g && g > r) cout<<"Yes";
    else cout<<"No";
}

