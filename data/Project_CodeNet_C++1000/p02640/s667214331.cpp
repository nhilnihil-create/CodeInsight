#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define lli long long
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
int main()
{
    fast
    int x,y;
    cin>>x>>y;
    if(y%2)
    cout<<"No";
    else{
        if(y>=2*x && y<=4*x)
        cout<<"Yes";
        else
        cout<<"No";
    }
}