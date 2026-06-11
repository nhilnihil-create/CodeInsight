#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 100000000
const int MOD = 1000000007;


int main(){
    /*
    int x;
    cin>>x;
    if(x>=30)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    */
    int n,d;
    cin>>n>>d;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        double x,y;
        cin>>x>>y;
        double dist = sqrt(x*x+y*y);
        if(dist<=d)
        {
            ans++;
        }
    }

    cout<<ans<<endl;
    return 0;
}