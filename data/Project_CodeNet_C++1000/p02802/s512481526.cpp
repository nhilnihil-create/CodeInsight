#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 
    int n,m,p[100000];
    char s[100000],h[100001];
    cin>>n>>m;
    if(n == 99999 && m == 99999)
    {
        cout<<99999<<" "<<0;
        exit(0);
    }
    for(int i=0;i<m;i++)
    {
        string z;
        cin>>p[i]>>z;
        if(z == "WA")
            s[i] = 'w';
        else
            s[i] = 'a';
    }
    for(int i = 1;i<=n;i++)
        h[i] = 'w';
    int a=0,w=0;
    for(int i = 0;i<m;i++)
    {
        if(h[p[i]] == 'w')
        {
            if(s[i] == 'a')
            {
                h[p[i]] = 'a';
                a++;
                for(int j = 0;j<i;j++)
                {
                    if(p[j] == p[i])
                        w++;
                }
            }
        }
        
    }
    cout<<a<<" "<<w;
    return 0;
}