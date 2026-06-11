#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
int main()
{
    IOS;
    //freopen("inputfile.txt","r",stdin);
    int k;cin>>k;
    string s;cin>>s;
    if(s.size()<=k)
    {
        cout<<s<<endl;
        return 0;
    }
    else
    {
        for(int i=0;i<k;i++)cout<<s[i];
cout<<"..."<<endl;
        return 0;
    }
}
//............ALHAMDULLILAH...........
