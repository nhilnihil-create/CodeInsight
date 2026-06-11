#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
const long long INF = numeric_limits<long long>::max();
int main()
{
    int a,b,c,ans,youki1,youki2;
    cin>>a>>b>>c;
    youki1 = a-b;
    youki2 = min(c,youki1);
    ans=c-youki2;
    cout << ans;
    return 0;
}