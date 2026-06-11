#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,k,l,c=0;
    string s;
    vector<char > v;
    cin>>n;
    cin>>s;
    s.push_back('A');
    for(i=0;i<n;i++)
    {
        if(s[i]!=s[i+1])
        {
//            cout<<s[i]<<endl;
            v.push_back(s[i]);
        }
    }
    cout<<v.size()<<endl;
}
