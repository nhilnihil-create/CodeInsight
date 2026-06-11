#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,mod,div,i;
    string s;
    vector<char>v;
    cin>>n;
    while(n>0)
    {
        n--;
        mod=n%26;
        //div=n/26;
        n/=26;
        /*if(mod==0)
        {
            mod=26;
            n--;
        }*/
        char j='a'+mod;
        v.push_back(j);
        //cout<<mod<<endl;
    }
    reverse(v.begin(),v.end());
    for(i=0; i<v.size(); i++)
        cout<<v[i];
    v.clear();
    return 0;
}
