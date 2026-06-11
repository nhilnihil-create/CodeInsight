#include<bits/stdc++.h>
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int main()
{
    fast;
    int k;
    cin>>k;
    string s;
    cin>>s;
    int m=s.length();
    if(k==m||k>m)
        {
            cout<<s<<endl;
            return 0;
        }
        else{
    for(int i=0;i<k;i++)
    {
      cout<<s[i];
    }
    cout<<"..."<<endl;
}
}
