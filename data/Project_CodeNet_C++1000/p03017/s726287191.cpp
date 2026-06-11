#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,a,b,c,d;cin>>n>>a>>b>>c>>d;
    a--;b--;c--;d--;
    str s;cin>>s;

    vector<int> v;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(v.size()%2)
        {
            if(s[i]=='.'){v.push_back(cnt);cnt=0;}
        }
        else
        {
            if(s[i]=='#'){v.push_back(cnt);cnt=0;}
        }
        cnt++;
    }
    v.push_back(cnt);

    bool ans=true;

    int posa=0,suma=0;
    for(auto vv:v){suma+=vv;if(suma>a)break;posa++;}
    
    int posb=0,sumb=0;
    for(auto vv:v){sumb+=vv;if(sumb>b)break;posb++;}
    
    int posc=0,sumc=0;
    for(auto vv:v){sumc+=vv;if(sumc>c)break;posc++;}
    
    int posd=0,sumd=0;
    for(auto vv:v){sumd+=vv;if(sumd>d)break;posd++;}

    for(int i=posa+1;i<posc;i+=2)if(v[i]>=2){ans=false;break;}
    for(int i=posb+1;i<posd;i+=2)if(v[i]>=2){ans=false;break;}

    if(d<c)
    {
        bool f=false;
        for(int i=posb+2;i<posd;i+=2)if(v[i]>=3){f=true;break;}

        f|=(s[b-1]=='.'&&s[b+1]=='.')||(s[b+1]=='.'&&s[b+2]=='.');
        f|=(s[d-1]=='.'&&s[d+1]=='.')||(s[d-1]=='.'&&s[d-2]=='.');
        
        ans&=f;
    }

    puts(ans?"Yes":"No");

    return 0;
}
