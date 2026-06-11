// date: June 20 2020
// author: Tibbarnit

#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
int n,a[200020],b[200020];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) cin>>a[i]>>b[i];
    sort(a+1,a+n+1);sort(b+1,b+n+1);
    if (n&1) cout<<(b[(n+1)/2]-a[(n+1)/2])+1;
    else cout<<b[(n+1)/2+1]+b[(n+1)/2]-a[(n+1)/2]-a[(n+1)/2+1]+1;
    return 0;
}
