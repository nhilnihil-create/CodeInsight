#include<iostream>
#include<string>
#include<set>
#define r(s) string(s.rbegin(),s.rend())
using namespace std;main(){int n,i;string s,h,t;for(cin>>n;cin>>s;){set<string> l;for(i=0;++i<s.size();)for(h=s.substr(0,i),t=s.substr(i),n=0;n++<2;swap(h,t)){l.insert(h+t);l.insert(r(h)+t);l.insert(h+r(t));l.insert(r(h)+r(t));}cout<<l.size()<<endl;}}