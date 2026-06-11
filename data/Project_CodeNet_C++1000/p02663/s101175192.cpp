#include<bits/stdc++.h>
using namespace std;

int main(){
    int h1,m1,h2,m2,k; cin >> h1 >> m1 >> h2 >> m2 >> k;
    int ans = (60*h2+m2) - (60*h1+m1) -k;
    cout << ans << endl;
}