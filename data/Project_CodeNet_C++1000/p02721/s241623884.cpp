#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main(){
    int n,k,c;
    cin>>n>>k>>c;
    string s;
    cin>>s;
    int k1=k;
    vector<int> start,end;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='o')
        {
            start.push_back(i);
            k--;
            i+=c;
        }
        if(k==0)
        {
            break;
        }
    }
    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i]=='o')
        {
            end.push_back(i);
            k1--;
            i-=c;
        }
        if(k1==0)
        {
            break;
        }
    }
    reverse(end.begin(),end.end());
    vector<int> v;
    for(int i=0;i<start.size();i++)
    {
        if(start[i]==end[i])
        {
            v.push_back(start[i]+1);
           
        }
    }
    for(auto i:v)
    {
        cout<<i<<"\n";
    }
    return 0;
}
