#include <bits/stdc++.h>

using namespace std;
int n,x;
map<int,int> f;
int nr,v[100001];
vector<int> w;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        if(f.count(v[i])==0)
            w.push_back(v[i]);
        f[v[i]]++;
    }
    if(w.size()==3)
    {
        int fr=f[v[1]];
        for(int i=1;i<=n;i++)
            if(f[v[i]]!=fr)
        {
            cout<<"No";
            return 0;
        }
        int ans=(w[0]^w[1]);
        if(ans==w[2])
            cout<<"Yes";
        else
            cout<<"No";
        return 0;
    }
    if(w.size()==2&&(w[0]==0||w[1]==0))
    {
        int nr1=w[0];
        int nr2=w[1];
        if(nr2==0)
            swap(nr1,nr2);
        if(f[nr2]==2*f[nr1])
            cout<<"Yes";
        else
            cout<<"No";
        return 0;
    }
    if(w.size()==1&&w[0]==0)
    {
        cout<<"Yes";
        return 0;
    }
    cout<<"No";
    return 0;
}
