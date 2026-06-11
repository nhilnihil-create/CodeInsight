//Bismillahir Rahmanir Rahim
//In the name of Allah the Most Merciful
//Astagfirullahil laji Rabbi Minkulli Jamio
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define int   long long  int
#define double  long double
#define rp(i,a,b)  for (int i = a; i <= b; i++)
#define hi ios_base :: sync_with_stdio(false); cin.tie(0);cout.tie(0);
int i,j,k;
main()
{
    int r,g,b,k;cin>>r>>g>>b>>k;
    int c=0;
    while(1)
    {
        if(g>r) break;
        g=g*2;
        c++;
    }
   // cout<<c<<endl;
    while(1)
    {
        if(b>g) break;
        b=b*2;
        c++;
    }
   // cout<<c<<endl;
    if(c<=k)cout<<"Yes"<<endl;else cout<<"No"<<endl;
}
