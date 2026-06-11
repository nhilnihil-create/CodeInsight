#include <bits/stdc++.h>
using namespace std;
#define lli long long

int main() 
{
    lli n,x;
    cin >> n;
    lli mx = -1;
    lli ans = 0;
    
    for(int i=0;i<n;i++){
        cin >> x;
        ans += max(mx-x,1LL*0);
        mx = max(mx,x);
    }
    
    cout<<ans<<endl;
    return 0;
}