#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int         long long   
#define double      long double
#define endl        "\n"
#define pb          push_back
#define PI          3.1415926535897932384626433832795l
#define F           first
#define S           second
#define mp          make_pair
#define f(i,n)      for(int i=0;i<n;i++)
#define fastio      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v)      (v).begin(),(v).end()
#define sort(v)     sort((v).begin(),(v).end())
#define rall(v)     (v).rbegin(),(v).rend()
#define rsort(v)     sort((v).rbegin(),(v).rend())
#define gcd(a,b)    __gcd((a),(b))

typedef pair<int,int> pii;  
typedef vector<int> vi;

signed main() 
{
    fastio;
    string s;
    cin>>s;
    bool flag=true;
    if(s.length()%2==1)
    {
        cout<<"No"<<endl;
        return 0;
    }
    for(int i=0;i<s.length();i++)
    {
        if(i&1)
        {
            if(s[i]!='i')
            {
                flag=false;
            }
        }
        else
        {
            if(s[i]!='h')
            {
                flag=false;
            }
        }
    }
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
}