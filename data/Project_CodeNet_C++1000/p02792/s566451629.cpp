#include <bits/stdc++.h>
using namespace std;
long long rev(string s,int n)
{
   	string revl,revh;
    revl.push_back(s[s.length()-1]);
  	revh.push_back(s[s.length()-1]);
  	int len=s.length();
  	int i=1;
  	while(i<len-1)
    {
      revl.push_back('0');
      revh.push_back('9');
      i++;
    }
  
  	revl.push_back(s[0]);
  	revh.push_back(s[0]);
  	//cout<<revl<<" "<<revh<<endl;
  	int rl,rh;
  	stringstream st(revl);
  	stringstream st1(revh);
  	st>>rl;
  	st1>>rh;
  	if(n<rl)return 0;
  	else if(n>=rl && n<=rh)
    {
      int ld=n%10;
      int l=n/10;
      long long  rtn=l-((revl[0]-'0')*pow(10,len-2));
      if(ld<(s[len-1]-'0'))rtn-=1;
      return rtn+1;
      
    }
  	else return (long long)pow(10,len-2);
}
int main()
{
  int n;
  cin>>n;
  long long ans=0;
  for(int i=n;i>=1;i--)
  {
    string s=to_string(i);
    int len=s.length();
    if(s[len-1]=='0')continue;
    if(len>=2)
    {
    	ans+=rev(s,n);
    	if(len>=2)ans+=2*((pow(10,len-2)-1)/9);
    	if(s[0]==s[len-1])ans+=2;
    }
    else ans++;
    //cout<<i<<' '<<ans<<endl;
  }
  cout<<ans<<endl;
  /*string s="25";
  cout<<rev(s,25)<<endl;*/
  return 0;
}