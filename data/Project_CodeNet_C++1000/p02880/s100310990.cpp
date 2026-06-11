//-- In The Name of God --
#include<bits/stdc++.h>
using namespace std;


#define      mod     1e9+7
#define      pai     acos(-1)
#define      ff      first
#define      ss      second
#define      ll      long long
#define      pb      push_back
#define      mp      make_pair
#define      endl    "\n"
#define      fii     freopen("input.txt","r",stdin);
#define      foo     freopen("output.txt","w",stdout);
#define      fast    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

const   ll   mx=1e5+100;

int main()
{
    fast;
    ll i,j,a,b,c,d,n,m,t;
    cin>>n;
    ll l=1,r=9;
    if(n%1==0||n%2==0||n%3==0||n%4==0||n%5==0||n%6==0||n%7==0||n%8==0||n%9==0)
    {
        if(n%1==0&&((n/1)>=l&&(n/1)<=r))
        {
            cout<<"Yes"<<endl;
        }
        else if(n%2==0&&((n/2)>=l&&(n/2)<=r))
        {
            cout<<"Yes"<<endl;
        }
        else if(n%3==0&&((n/3)>=l&&(n/3)<=r))
        {
            cout<<"Yes"<<endl;
        }
        else if(n%4==0&&((n/4)>=l&&(n/4)<=r))
        {
            cout<<"Yes"<<endl;
        }
        else if(n%5==0&&((n/5)>=l&&(n/5)<=r))
        {
            cout<<"Yes"<<endl;
        }
        else if(n%6==0&&((n/6)>=l&&(n/6)<=r))
        {
            cout<<"Yes"<<endl;
        }
        else if(n%7==0&&((n/7)>=l&&(n/7)<=r))
        {
            cout<<"Yes"<<endl;
        }
        else if(n%8==0&&((n/8)>=l&&(n/8)<=r))
        {
            cout<<"Yes"<<endl;
        }
        else if(n%9==0&&((n/9)>=l&&(n/9)<=r))
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }

    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}

