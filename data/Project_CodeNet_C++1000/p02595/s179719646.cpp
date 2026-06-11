#include <bits/stdc++.h>

using namespace std;
long long n,d,ans=0;
long double x,y;
int main()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        double len=sqrt(x*x+y*y);
        if(len<=d)ans++;
    }
    cout<<ans<<endl;
    return 0;
}