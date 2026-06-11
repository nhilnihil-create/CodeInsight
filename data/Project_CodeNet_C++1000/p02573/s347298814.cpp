    #include<bits/stdc++.h> 
    using namespace std;
    typedef long long ll;
    const int N=2e5+5;

    int n,m;
    
    int f[N];
    int find(int x)
    {
        if(f[x]==x)
            return x;
        else
            return f[x]=find(f[x]);
    }
    
    int h[N];
    int ans;
    int main()
    {
        ios::sync_with_stdio(false);
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            f[i]=i;
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            int tx=find(x);
            int ty=find(y);
            if(tx!=ty)
                f[tx]=ty;
        }
        for(int i=1;i<=n;i++)
        {
            h[find(i)]++;
            ans=max(ans,h[find(i)]);
        }
        cout<<ans<<endl;
        
    }