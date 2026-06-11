#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    map<string,int> a;
    vector<string> ans;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        a[s]++;
    }
    int m=0;
    for(auto p : a) m=max(m,p.second);
    for(auto p:a)
        if(p.second==m) cout<<p.first<<endl;
}