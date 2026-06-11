//Author - Rahil Malhotra
#include <bits/stdc++.h>
using namespace std;

template <typename T> void print(T t) { cout<<t<<endl; }
template<typename T, typename... Args> void print(T t, Args... args) { cout<<t<<" "; print(args...); }

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int n,k;
int mod=1e9+7;
int table[2005][2005];
int32_t main()
{
    IOS;
    cin>>n>>k;
    table[0][0]=1;
    for(int i=1;i<=2001;i++)
    {
        table[i][0]=1;
        for(int j=1;j<=i;j++)
            table[i][j]=(table[i-1][j]+table[i-1][j-1])%mod;
    }
    for(int i=1;i<=k;i++)
    {
        //method for k blue balls = x1+x2...+xi=k; x1>0 x2>0... xi>0
        //formula =(k-1,i-1)

        //method for n-k red balls = Coeff of x^(n-k) in x^(i-1)*(1+x+x^2...)^(i+1)
        //Coeff of x^(n-k-i+1) in (1-x)^(-(i+1))
        //formula =(i+1+n-k-i+1-1,n-k-i+1) = (n-k+1,n-k-i+1)

        if(k-1<i-1 || n-k+1<n-k-i+1)
            print(0);
        else
        {
            int ans=table[k-1][i-1];
            ans*=table[n-k+1][n-k-i+1];
            ans%=mod;
            print(ans);
        }
    }
}