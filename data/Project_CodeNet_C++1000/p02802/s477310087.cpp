#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<bool>p(m,false);
    vector<int>x(n,0);
    int r;
    string s;
    int ac=0,pen=0;
    for(int i=0;i<m;i++)
    {
        cin>>r>>s;
        if(p[r-1]==false && s=="AC")
        {
            p[r-1]=true;
            ac++;
            pen+=x[r-1];
            x[r-1]=0;
        }
        else if(p[r-1]==false)
        {
            x[r-1]++;
        }
    }
    cout<<ac<<" "<<pen<<"\n";
}
