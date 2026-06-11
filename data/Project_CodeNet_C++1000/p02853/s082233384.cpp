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
    int x,y;
    cin>>x>>y;
    if(x==1&&y==1)cout<<1000000<<endl;
    else{
        int ans=0;
        if(x==3)ans+=100000;
        else if(x==2)ans+=200000;
        else if(x==1)ans+=300000;
        
        if(y==3)ans+=100000;
        else if(y==2)ans+=200000;
        else if(y==1)ans+=300000;
        cout<<ans<<endl;
    }
    return 0;
}