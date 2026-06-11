#include <iostream>
#include<cstring>

using namespace std;
int a[200007];
//WWRRWRR
int main()
{
    int n; cin >> n;
    int k; cin >> k;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    int l=1, r=1000000007;
    while(l<r) {
        int m=(l+r)>>1;
        long long ans=0;
        for(int i=0; i<n; i++) {
            ans += (1ll*a[i]+m-1)/m-1;
            if(ans>k) break;
        }
        if(ans>k) {
            l=m+1;
        } else {
            r=m;
        }
    }
    cout << r << '\n';
}
