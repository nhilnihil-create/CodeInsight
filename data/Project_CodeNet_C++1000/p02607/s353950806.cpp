#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int ans = 0;
    for (int i=1; i<=n; i++){
        int a; cin >> a;
        if(i*a%2==1) ans ++;
    }
    cout << ans << endl;
}