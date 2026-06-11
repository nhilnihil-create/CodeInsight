/*
** author:mahmoud magdy
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

inline int D()
{
    int m ;
    cin>>m;
    return m ;
}
inline ll lD()
{
    ll m ;
    cin>>m;
    return m ;
}
inline double dD()
{
    double m;
    cin>>m;
    return m;
}
void fast()
{
    ios_base :: sync_with_stdio( 0 ) ;
    cin.tie( 0 ) ;
    cout.tie( 0 ) ;
}
int main()
{
    fast();
    int n=D();
    string s;
    cin>>s;
    for(int i=0;i<s.length();++i){
        int x=n;
        while(x--){
            if(s[i]=='Z')s[i]='A';
            else
                s[i]++;
        }
    }
    cout<<s<<endl;
}
