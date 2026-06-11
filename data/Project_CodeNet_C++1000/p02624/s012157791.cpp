#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    long n;
    cin >> n;
    long ans = 0;
    vector<long> a(n+1,0); 
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i) a[j]++;
    }
    for(int i=1;i<=n;i++) ans += i*a[i];
    cout << ans << endl;
}
