#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,a,b) for(int i=a;i<b;i++)
#define each(it,v) for(auto it : v)
#define mod 1000000007
#define All(v) (v).begin(),(v).end()
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int,int>>
#define vv vector<vector<int>>
template<class T> T gcd(T a,T b) {return b?gcd(b,a%b):a;}
template<class T> T lcm(T a,T b) {return a/gcd(a,b)*b; }
template<class T> bool isPrime(T num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false;

    double sqrtNum = sqrt(num);
    for (T i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

using namespace std;

int n;

main()
{
        cin>>n;

        vector<pair<string,int>> v(n);

        each(&it,v)cin>>it.first>>it.second;

        string x;
        cin>>x;

        int ans=0;
        bool f=false;
        each(it,v)
        {
            if(f)ans+=it.second;
            if(it.first==x)f=true;

        }
        cout<<ans<<endl;
}