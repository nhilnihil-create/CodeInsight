#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define int long long
signed main(){
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int n,k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int mx=0;
    for(int i = 0; i < n; i++) mx=max(mx,a[i]);

    int r=mx;
    int l=0;

    while(r-l>1) {
        int mid=l+(r-l)/2;
        int cnt=0;
        for(int i = 0; i < n; i++) {
            int add=(a[i]+mid-1)/mid;
            cnt+=(add-1);
        }

        if(cnt>k)  l=mid;
        else       r=mid;
    }

    cout << r << "\n";
    return 0;
}