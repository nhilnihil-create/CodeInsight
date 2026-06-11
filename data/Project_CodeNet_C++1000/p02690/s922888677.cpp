#include <bits/stdc++.h>
#define int long long int
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x;
    cin>>x;
    pair<int,int> ans;
    for(int i=0;i<=1000;i++)
    {
        for(int j=0;j<=1000;j++)
        {
            if(pow(i,5)-pow(j,5)==x)
            {
                
                ans = make_pair(i,j);
                break;
            }
            if(pow(i,5)-pow(-j,5)==x)
            {
                ans = make_pair(i,-j);
                break;
            }

            if(pow(-i,5)-pow(j,5)==x)
            {
                ans = make_pair(-i,j);
                break;
            }
            if(pow(-i,5)-pow(-j,5)==x)
            {
                ans = make_pair(-i,-j);
                break;
            }
        }
    }
    cout<<ans.first<<" "<<ans.second;
    return 0;
}