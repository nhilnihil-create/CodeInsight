#include<bits/stdc++.h>

using namespace std;
int main(){
    long long a,b;
    cin >> a >> b;
    long ans = (a+b);
    if(ans%2==0) cout << ans/2 << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}