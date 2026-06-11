#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
#define  pi  pair<int,int>
#define  pb  push_back
#define  F   first
#define  S   second
#define  B   begin()
#define  E   end()
const int N=2e5+3;
string s,p;
//vector<int>v;
//map<int,int>mp;

int main()
{
    ft
    int t,i,j,n,m,l,r;
    cin>>s;
    n=s.size();
    for(i=0;i+1<n;i++)
    {
        if(s[i]==s[i+1])
        {
            cout<<"Bad\n";
            return 0;
        }
    }
    cout<<"Good\n";
    return 0;
}

