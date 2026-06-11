//Bismillahir Rahmanir Rahim
//In the name of Allah the Most Merciful
//Astagfirullahil laji Rabbi Minkulli Jamio
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define int   long long  int
#define double  long double
#define mod 1000000007
#define rp(i,a,b)  for (int i = a; i <= b; i++)
#define hi ios_base :: sync_with_stdio(false); cin.tie(0);cout.tie(0);
int i,j,k;
main()
{
    int a,b;cin>>a>>b;
    int ar[4]={0};
    ar[a]=1;ar[b]=1;
    for(i=1;i<=3;i++)
    {
        if(ar[i]==0)cout<<i<<endl;
    }
}
