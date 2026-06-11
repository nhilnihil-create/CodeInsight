#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    int nn = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i]<0) nn++;
    }
    if(nn==0) nn=1;
    if(nn==n) nn=n-1;
    sort(a.begin(),a.end());

    int ans=0;
    for(int i = 0; i < nn; i++) {
        ans-=a[i];
    }
    for(int i = nn; i < n; i++) {
        ans+=a[i];
    }
    cout << ans << "\n";

    for(int i = nn; i < n-1 ; i++) {
        cout << a[0] << " " << a[i] << "\n";
        a[0]-=a[i];
    }
    for(int i = 0; i < nn; i++) {
        cout << a[n-1] << " " << a[i] << "\n";
        a[n-1]-=a[i];
    }

    return 0;
}