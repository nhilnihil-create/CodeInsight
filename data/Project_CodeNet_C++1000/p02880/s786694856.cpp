#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define ff first
#define ss second
#define p pair<int,int>
#define pb push_back
#define endl '\n'
#define w(t) ll test;cin>>test;while(test--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define pi acos(-1)

int main()
{
    fast;
    int n;
    cin>>n;
    //bool flag=false;
    for(int i=1;i<=9;i++)
    {
        int temp;
        if(n%i==0)
        {
            temp=n/i;
       // cout<<i<<" "<<temp<<endl;
        if(temp<=9&&temp>=1)
        {
            cout<<"Yes"<<endl;
            return 0;
        }

        }
    }
    cout<<"No"<<endl;
}

