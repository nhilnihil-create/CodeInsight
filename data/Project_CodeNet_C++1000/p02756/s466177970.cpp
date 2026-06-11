#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
deque<char> s;
string st,ans;
int q,opt,f,fz,len;
char c;
int main() {
 cin>>st;
 len=st.size();
 for(int i=0;i<len;i++)
  s.push_back(st[i]);
 scanf("%d",&q);
 while(q--) {
  scanf("%d",&opt);
  if(opt==1)
   fz^=1;
  else {
   scanf("%d",&f);
   cin>>c;
   if(fz^(f==1))
    s.push_front(c);
   else
    s.push_back(c);
  }
 }
 while(!s.empty()) {
  ans.push_back(s.front());
  s.pop_front();
 }
 if(fz)
  reverse(ans.begin(),ans.end());
 cout<<ans;
 return 0;
}