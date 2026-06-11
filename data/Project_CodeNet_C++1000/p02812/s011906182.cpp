#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;

#define INF 1e9
#define PI 3.141592653589793238
#define N 1000000010
#define mod 1000000007
typedef long long ll;

int main() {
    int n,ans=0;cin>>n;
    string s;cin>>s;
    for(int i=0; i<n-2; i++){
        if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C') ans++;
    }
    cout<<ans<<endl;

    return 0;
}