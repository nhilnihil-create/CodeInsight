#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define test int t; cin>>t; while(t--)


int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=9;i++)
    {
        if(n%i==0)
        {
            int d=n/i;
            if(d<=9)
            {
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}
