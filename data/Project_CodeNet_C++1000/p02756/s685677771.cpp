#include<bits/stdc++.h>
#define ll long long
#define pb push_back
long long int mod = (long long int)1000000007;
using namespace std;

void solve()
{
    ll i,j,k,n;
    std::cout.precision(10);
    int yes=0;
    string s;
    int q;
    cin>>s>>q;
    int x=0;
    int c=1;
    int d=2;
    stack<char>fro;
    queue<char>bac;
    while(q--)
    {
        int a,b;
        cin>>a;
        if(a==1)
        {
            x++;
            c=3-c;
            d=3-d;
        }
        else
        {
            cin>>b;
            char ch;
            cin>>ch;
            if(b==c)
            {
                fro.push(ch);
            }
            else
            {
                bac.push(ch);
            }
        }
    }
    
    string l="";
    while(!fro.empty())
    {
        l+=fro.top();
        fro.pop();
    }
    
    string r="";
    while(!bac.empty())
    {
        r+=bac.front();
        bac.pop();
    }
    
    s=l+s;
    s=s+r;
    if(x%2==1)
    {
        reverse(s.begin(),s.end());
    }
    cout<<s<<"\n";
    
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int i,j,k;
    int t;
    std::cout.precision(10);
    t=1;
    while(t--)
    {
        solve();
        cout<<"\n";
    }
}