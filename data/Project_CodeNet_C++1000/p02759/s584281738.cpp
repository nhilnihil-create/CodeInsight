#include <bits/stdc++.h>          
using namespace std;               

int main() {
    int N;
    cin >> N;
    int ans;
    if(N%2==0) ans = N/2;
    else ans = N/2+1;
    cout << ans << endl;
}