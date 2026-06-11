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
string s;
int main()
{
    ft
    int t,i,j,n,m,l,r;
    cin>>n>>s;
    m=s.size();
    for(i=0;i<m;i++)
    {
        l=s[i]-65;
        l+=n;
        l%=26;
        s[i]=(char)(l+65);
    }
    cout<<s<<"\n";
    return 0;
}

