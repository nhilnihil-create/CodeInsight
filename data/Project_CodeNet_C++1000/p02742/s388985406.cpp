#include <bits/stdc++.h>
#define rep(i,k,n) for(int i=k;i<n;++i)
#define repe(i,k,n) for(int i=k;i<=n;++i)
typedef long long in;

using namespace std;

int main()
{
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(false);
    in h,w;
    cin >> h >> w;
    in blo = h*w;
    if (h == 1 || w == 1) {
        cout << 1;
        return 0;
    }

    if (blo % 2 ==0){
        cout << blo/2;
    }else cout << (blo+1)/2 ;
    return 0;
}
