#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<iterator>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<string>v(n);
    map <string,int> m;
    set <string> s;
    map <string,int> :: iterator it;

    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }

    for(int i=0; i<n; i++)
    {
        if(m.count(v[i]))
            m[v[i]]++;
        else
            m[v[i]]=1;
    }

    int high=0;
    for(it=m.begin(); it!=m.end(); it++)
        high=max(it->second,high);

    for(it=m.begin(); it!=m.end(); it++)
    {
        if(it->second==high)
            s.insert(it->first);
    }

    set <string> :: iterator itr;
    for(itr=s.begin(); itr!=s.end(); itr++)
        cout<<*itr<<endl;

    return 0;
}