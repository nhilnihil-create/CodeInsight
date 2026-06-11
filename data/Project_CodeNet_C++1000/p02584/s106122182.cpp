#include <bits/stdc++.h>
using namespace std;
int const MX = 2e5 + 2, MOD = 1e9 + 7;

int main()
{
    int t = 1;
//    cin>>t;
    while(t--){
        long long  x, k , d;
        cin>>x>>k>>d;
        x = abs(x);
        long long n = x/d;
        if(k < n) cout<<x - k*d;
        else{
            long long s = x - n*d, cnt = k - n;
            if(cnt % 2 == 0) cout<<s;
            else cout<<abs(d - s);
        }
    }
}


