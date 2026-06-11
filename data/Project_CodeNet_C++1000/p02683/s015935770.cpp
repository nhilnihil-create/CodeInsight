#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int i=0,j=0,n,m,x,c[20000],a[200][200],saisyo=999999999999,u=0,g[100],k,q=0,i2,cc=0;
    string b,b2;
    cin >> n >> m >> x;
    for(i=0;i<n;i++)
    {
        cin >> c[i];
        for(j=0;j<m;j++)
        {
            cin >> a[i][j]; 
        }
    }
 for (int bit = 0; bit < (1<<n); ++bit)
    {
        q=0;
        u=0;
        for(k=0;k<m;k++)
        {
            g[k]=0;
        }
        for(i=0;i<n;i++)
        {
            if(((bit >> i)&1)==0)
            {
                continue;
            }
            for(j=0;j<m;j++)
            {
                g[j]+=a[i][j];
            }
            q+=c[i];
        }
        for(i2=0;i2<m;i2++)
        {
            if(g[i2]>=x)
            {
                u++;
            }
        }
        if(u==m && saisyo>q)
        {
            saisyo=q;
            cc++;
        }
    }
    if(cc==0)
    {
        cout << "-1" << endl;
        return 0;
    }
    cout << saisyo << endl;   
    return 0;
}