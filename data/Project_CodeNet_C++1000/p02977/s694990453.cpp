#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> >v;

int main()
{
    int n;
    scanf("%d",&n);
    if(n<3 || __builtin_popcount(n)==1)
        puts("No");
    else
    {
        puts("Yes");
        v.push_back({1,2});
        v.push_back({2,3});
        v.push_back({3,n+1});
        v.push_back({n+1,n+2});
        v.push_back({n+2,n+3});

        for(int i=4;i<n;i+=2)
        v.push_back({n+1,i}),v.push_back({i,i+1});

        for(int i=n+5;i<=2*n;i+=2)
        v.push_back({n+1,i}),v.push_back({i,i-1});


        if(n%2==0)
        {
            int x,y;
            for(int i=0;;i++)
            {
                if(1<<i&n)
                {
                    x=1<<i;break;
                }
            }
            y=n^x^1;
           v.push_back({x==2?n+2:x,n});
           v.push_back({n+y,2*n});
        }
        for(auto i :v)
            printf("%d %d\n",i.first,i.second);

    }

    return 0;
}
