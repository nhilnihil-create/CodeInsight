#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int X;
    cin >> X;

    ll de=360;
    while(de%X != 0) de+=360;
    int ans=de/X;
    cout<<ans<<endl;
    return 0;
}