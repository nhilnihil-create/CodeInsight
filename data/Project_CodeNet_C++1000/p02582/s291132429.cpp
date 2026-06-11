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
    string s;
    cin>>s;
    int ans;
    if(0==count(s.begin(),s.end(),'R'))ans=0;
    else if(1==count(s.begin(),s.end(),'R'))ans=1;
    else if(3==count(s.begin(),s.end(),'R'))ans=3;
    else {
        if(s[1]=='S')ans=1;
        else ans=2;
    }
    cout<<ans<<endl;
    return 0;
}