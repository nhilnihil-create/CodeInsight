#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    map<string , int> m;
    for(int i=0;i<n;i++)
    {
        string x;
        cin>>x;
        m[x]++;
    }
    map<string , int>::iterator it = m.begin();
    int max = 0;
    while( it!= m.end() )
    {

        if( it->second > max)
        {
            max = it->second;
        }
        it++;
    }
    vector<string> ans;

    it = m.begin();
    while( it!= m.end())
    {
        if( it->second == max)
        {
            string temp = it->first;
            ans.push_back(temp);
        }
        it++;
    }
    sort( ans.begin() , ans.end());
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
}