#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 100000000

int main()
{
    /*ABC144 B
    int x;
    cin>>x;
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(x==i*j)
            {
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
    */
    /*ABC150 B
    int n;
    string s;
    cin>>n>>s;
    int count = 0;
    for(int i=0;i<n-2;i++)
    {
        if(s[i]=='A')
        {
           if(s[i+1]=='B')
           {
               if(s[i+2]=='C')
               {
                   count++;
               }
           }
        }
    }
    cout<<count<<endl;
    */

    int n;
    cin>>n;
    int count = 0;
    for(int i=1;i<=n;i++)
    {
        int even=0;
        int num = i;
        while(num)
        {
            num/=10;
            even++;
        }
        if(even%2!=0)
        {
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}