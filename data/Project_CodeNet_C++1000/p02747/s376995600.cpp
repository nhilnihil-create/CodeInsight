#include <bits/stdc++.h>
#define per(i,a,n) for(int i=a;i<=n;i++)
#define ls l+mid>>1

#define rs mid+1+r>>1
using namespace std;
typedef  long long ll;
stack<char>s;
string str;
int main()
{
  cin>>str;
  /*if(str[0]=='h')
  s.push(str[0]);
  else {cout<<"No";return;}*/
  for(int i=0;i<str.size();i++){
      if(str[i]!='h'&&str[i]!='i'){{cout<<"No";return 0;}}
      if(str[i]=='h'&&s.size()==0){
        s.push(str[i]);
      }
      else if(str[i]=='i'&&s.size()==0){cout<<"No";return 0;}
      else if(str[i]=='i'&&s.top()=='h')s.pop();
      else {cout<<"No";return 0;}
  }
  if(s.size())cout<<"No";
  else
  cout<<"Yes"<<endl;
  return 0;
}

