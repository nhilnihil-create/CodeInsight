///in the name of ALLAH
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  //  ll p=100;
    //while(p--){
    ll t;
    cin>>t;
    bool f=0;
    for(int i=1;i<=9;i++)
    {
        if(t%i==0)
        {
            if(t/i>=1 && t/i<=9)
            {
                f=1;break;
            }
        }
    }
    if(f==1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}



