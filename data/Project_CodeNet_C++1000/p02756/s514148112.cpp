#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
 // freopen("input.txt","r",stdin);
#endif

  string s;
  cin>>s;
  int q;
  cin>>q;
  string pref="";
  string suff="";
  int rev=0;
  for(int i=0;i<q;i++)
  {
      int op;
      cin>>op;
      if(op==1)
      {
        swap(pref,suff);
        rev++;
      }
      else
      {
        int num;
        char ch;
        cin>>num>>ch;
        if(num==1)
          pref+=ch;
        else
          suff+=ch;
      }
  }
  if(rev%2!=0)
  {
    reverse(s.begin(),s.end());
  }
  reverse(pref.begin(),pref.end());
  cout<<pref+s+suff<<endl;
  return 0;
}