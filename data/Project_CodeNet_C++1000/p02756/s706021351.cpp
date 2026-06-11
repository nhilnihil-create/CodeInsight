#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 int x,q,f,r;
 r=0;
 char p;
 string s,t;
 cin >> s >> q;
 while(q--)
 {
  cin >> x;
  if(x==1)
  r=(r+1)%2;
  else
  {
   cin >> f >> p;
   f=(f+r)%2;
   if(f==0)
   s.append(1,p);
   else
   {
    t="";
    t.append(1,p);
    t.append(s);
    s=t;
   }
  }
 }
 if(r==1)
 reverse(s.begin(),s.end());
 cout << s;
 return 0;
}