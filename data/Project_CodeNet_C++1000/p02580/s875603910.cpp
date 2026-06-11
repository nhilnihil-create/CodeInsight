#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int N=3e5+5;
int h,w,n;
int rc[N],rw[N];
vector<int> totc,totw;
set<pair<int,int>> rcw;
int maxr,maxw;

int main()
{
    ios::sync_with_stdio(false);
    cin>>h>>w>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        rc[x]++;
        rw[y]++;
        maxr=max(rc[x],maxr);
        maxw=max(rw[y],maxw);
        rcw.insert({x,y});
    }
    for(int i=0;i<=h;i++)
    {
        if(rc[i]==maxr) 
            totc.push_back(i);
    }
    for(int i=0;i<=w;i++)
    {
        if(rw[i]==maxw) 
            totw.push_back(i);
    }    
    
    for(int i=0;i<totc.size();i++)
        for(int j=0;j<totw.size();j++)
        {
            if(!rcw.count({totc[i],totw[j]}))
            {
                cout<<maxr+maxw<<endl;
                return 0;
            }
        }
    cout<<maxr+maxw-1<<endl;
    
    return 0;
}