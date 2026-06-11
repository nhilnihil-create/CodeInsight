//Bismillahir Rahmanir Rahim
//In the name of Allah the Most Merciful
//Astagfirullahil laji Rabbi Minkulli Jamio Watubi elai
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define double long double
#define MX 10000008
#define cs int t;cin>>t;while(t--)
int i,j,k;
int r,s;
int main()
 {
    int x;
    cin>>x;
    int p=0;
    for(i=1;i<=9;i++)
    {
        if(x%i==0)
        {
            int k=x/i;
            if(k>=1&&k<=9)
            {
                p=k;

            }
        }
    }
    if(p) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
 }
