#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll p[20];
int main()
{
    ll a,b,c,d,e,f,g;
    cin>>a>>b;
    if(b%2==1)
        cout<<"No"<<endl;
    else
    {
        if(b/2-a>=0&&2*a-b/2>=0)
          cout<<"Yes"<<endl;
        else
          cout<<"No"<<endl;

    }
    return 0;
}
