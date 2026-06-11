#include <bits/stdc++.h>
#define int long long int
using namespace std;

signed main() {
    int n,x,y;
    cin>>n>>x>>y;
    int dis;
    map<int,int> m;
    m[y-x]++;
    for(int i=1;i<=n-1;i++)
    {
        m[i]=0;
        
        for(int x1=1;x1<=n-i;x1++)
        {
            int y1=x1+i;
            if(x1<=x || y<=y1)
            {
                if(x1<=x && y<=y1)
                dis = (x-x1+y1-y+1);
                else if(x1<=x)
                dis = min(y1-x1,x-x1+y-y1+1);
                else if(y<=y1)
                dis = min(x1-x+1+y1-y,y1-x1);
                m[dis]++;
            }
            else if(x<=x1 && y1<=y)
            {
                dis = min(x1-x+1+y-y1,y1-x1);
                m[dis]++;
            }
            else
            {
                dis = (y1-x1);
                m[dis]++;
            }
        }
    }
    for(auto i:m)
    cout<<i.second<<endl;
    }