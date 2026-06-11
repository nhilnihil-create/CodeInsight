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
string s,p[]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
int main()
{
    ft
    int t,i,j,n,m,l,r;
    cin>>s;
    for(i=0;i<7;i++)
    {
        if(p[i]==s)
        {
            cout<<(7-i)<<"\n";
            return 0;
        }
    }
}

