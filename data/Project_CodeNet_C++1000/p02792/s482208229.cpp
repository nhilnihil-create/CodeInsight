#include<bits/stdc++.h>
#define FastRead                      \
                                    ios_base::sync_with_stdio(false); \
                                    cin.tie(0);
#define ll long long
#define endl "\n"
#define f for
using namespace std;
int main()

{
    FastRead
    ll int n,i,last,num,first,sum=0,j,c[10][10]= {0};
    cin>>n;
    f(i=1; i<=n; i++)
    {
        last=i%10;
        num=i;
        while(num!=0)
        {
            first=num%10;
            num=num/10;
        }

        c[first][last]++;

    }
    f(i=0; i<10; i++)
    {
        f(j=0; j<10; j++)
        {
            sum=sum+(c[i][j]*c[j][i]);
        }
    }
    cout<<sum;
    return 0;

}