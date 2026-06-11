#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   string s;
   set<int>s1;
   vector<string>v;
   set<int>::iterator it;
   set<string>s2;
   set<string>::iterator i1;
   map<string,int>mp;
   cin>>n;
   for(int i=1;i<=n;i++)
   {
       cin>>s;
       v.push_back(s);
       s1.insert(mp[s]);
       mp[s]++;
   }
   mp.clear();
   it=s1.end();
   it--;
   for(int i=0;i<n;i++)
   {
       if(mp[v[i]]==*it)
        s2.insert(v[i]);
       mp[v[i]]++;
   }
   for(i1=s2.begin();i1!=s2.end();i1++)
    cout<<*i1<<endl;
}
