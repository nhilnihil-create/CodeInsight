#include<bits/stdc++.h>
using namespace std;
main(){
  string s,t;
  int l,i;
  while(cin>>s>>l,l){
    map<string,int>m;
    m.insert({s,0});
    for(i=1;;++i){
      for(;s.size()<l;)s+='0';
      sort(s.begin(),s.end());
      t=s;
      sort(s.rbegin(),s.rend());
      int x=stoi(s),y=stoi(t);
      s=to_string(abs(x-y));
      if(m.find(s)!=m.end())break;
      m.insert({s,i});
    }
    int x=m.find(s)->second;
    cout<<x<<' '<<s<<' '<<i-x<<endl;
  }
}