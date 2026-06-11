#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<bitset>
#include<queue>
#include<string>
#include<vector>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,n,a) for(int i=n;i>a;i--)
#define mem0(x) memset(x,0,sizeof(x))
#define memff(x) memset(x,INF,sizeof(x))
#define INF 100000000
using namespace std;
typedef pair<int,int> p;
typedef long long LL;
int aa[15];
int main()
{
    //freopen("input.in","r",stdin);
    int n;
    bitset<10> dis;
    cin>>n;
    while(n--)
    {
        for(int i=1;i<=10;i++)
        cin>>aa[i];
        int all=1024;
        while(all>0)
        {
            dis=static_cast<bitset<10> >(all);
            bool flag=true;
            int left=0,right=0;
            for(int i=1;i<=10;i++)
            {
                if(dis[i-1])
                {
                    if(aa[i]>left)
                    {
                         left=aa[i];
                    }
                    else
                    {
                        flag=false;
                        break;
                    }
                }
                else
                {
                    if(aa[i]>right)
                    {
                        right=aa[i];
                    }
                    else
                    {
                        flag=false;
                        break;
                    }
                }
            }
            if(flag)
            {
                break;
            }
            else all--;
        }
        if(all>0)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
    return 0;
}