#include<bits/stdc++.h>
using  namespace  std;

#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define sq(x)   (x)*(x)
#define PI      acos(-1.0)
#define all(x) x.begin(),x.end()
#define nl      '\n'

typedef long long int ll;
typedef unsigned long long int  llu;

int main()
{
    int n,sz,ok=0;
    cin>>n;
    string s;
    cin>>s;
    sz=s.size();
    if(sz%2==1)
    {
        cout<<"No"<<nl;
        return 0;
    }
    for(int i=0,j=(sz/2); i<(sz/2) && j<sz; i++,j++)
    {
        if(s[i]!=s[j])
            ok=1;
    }
    if(ok==0)
        cout<<"Yes"<<nl;
    else cout<<"No"<<nl;
    return 0;
}

