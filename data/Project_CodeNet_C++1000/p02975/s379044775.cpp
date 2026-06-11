#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;

    bool allzero=true;

    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        m[a]++;
        if(a!=0)allzero=false;
    }

    if(allzero){puts("Yes");return 0;}

    bool ans=false;
    if(n%3==0)
    {
        if(m.size()==3)
        {
            pair<int,int> p[3];
            int pos=0;
            for(auto mm:m){p[pos]=mm;pos++;}
            if(p[0].se==p[1].se&&p[1].se==p[2].se)
            {
                int a=p[0].fi,b=p[1].fi,c=p[2].fi;
                int xo=a^b^c;
                ans=xo==0;
            }
        }
        else if(m.size()==2)
        {
            pair<int,int> p[2];
            int pos=0;
            for(auto mm:m){p[pos]=mm;pos++;}
            ans=(p[0].se==p[1].se*2&&p[1].fi==0)||(p[1].se==p[0].se*2&&p[0].fi==0);
        }
    }

    puts(ans?"Yes":"No");

    return 0;
}
