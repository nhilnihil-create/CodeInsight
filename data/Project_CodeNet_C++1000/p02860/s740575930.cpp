#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n,i;
    string s;
    cin>>n>>s;
    if(n&1) cout<<"No";
    else
    {int a=0;
       for(i=0;i<n/2;i++)
       {
           if(s[i]!=s[n/2+i]){a=1;break;}
       }
       if(a) cout<<"No";
       else cout<<"Yes";
    }cout<<endl;
    return 0;
}
