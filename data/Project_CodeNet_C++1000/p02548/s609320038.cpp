#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000010;
 typedef pair<int,int> pii;
 int a[N][2];
 int cnt;
 bool st[N];
 int prime[N];
 void get_prime(int n)
 {
    for(int i=2;i<=n;i++)
    {
        if(!st[i])
        {
            prime[cnt++]=i;
        }
        for(int j=0;i*prime[j]<=n;j++)
        {
            st[i*prime[j]]=true;
            if(i%prime[j]==0)   break;
        }
    }
 }
int main()
{
    //get_prime(1000000);
    int n;
    cin>>n;
    long long res=0;
    for(int i=1;i<=n-1;i++)
    {
        //cout<<n<<endl;
        int t=n-i;
        long long temp=1;;
        for(int j=2;j*j<=t;j++)
        {
       //  long long temp=1;
            int ct=0;
            if(t%j==0)
            {
                while(t%j==0)
                {
                    t/=j;
                    ct++;
                }
            }
            temp=temp*(ct+1);
        }
        if(t>1)
            temp*=2;
        res+=temp;
    }
    cout<<res<<endl;
    return 0;
}  