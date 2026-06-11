#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descsort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main(void)
{
    int x;
    cin>>x;
    int ans;
    if(400<=x&&x<=599)ans=8;
    else if(600<=x&&x<=799)ans=7;
    else if(800<=x&&x<=999)ans=6;
    else if(1000<=x&&x<=1199)ans=5;
    else if(1200<=x&&x<=1399)ans=4;
    else if(1400<=x&&x<=1599)ans=3;
    else if(1600<=x&&x<=1799)ans=2;
    else if(1800<=x&&x<=1999)ans=1;
    cout<<ans<<endl;
    return 0;
}