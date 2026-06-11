#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    unordered_map<string,int>m;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        m[s]++;
    }
    ll max=0;
    for(auto x:m)
    {
        if(x.second>max)
            max=x.second;
            
    }
    vector<pair<string,int>>v;
    for(auto x:m)
    {
        if(x.second==max)
            v.push_back(make_pair(x.first,x.second));
    }
    sort(v.begin(),v.end());
    for(auto x:v)
        cout<<x.first<<endl;
    return 0;
}
