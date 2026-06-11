#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
    int n,ans=0;
    cin>>n;
    map<string,int> s; 
    for(int i=0;i<n;i++)
    {
        string t;
        cin>>t;
        if(s[t]==0)
        {
            ans++;
            s[t]++;
        }
    }
    cout<<ans;
}