#include<bits/stdc++.h>
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cerr<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}

using namespace std;


bool check(int n,int i)
{
  if((n|i)==n)
  return true;
  else return false;
}

int main()
{
  __;
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> v;
  for(int i=0;i<n;i++)
  {
    if(check(n-1,i)) 
    {
      v.push_back(i);
      continue;
    }
  }

  set<char> se;
  bool zero = false;
  for(int i=0;i<s.size();i++) 
  {
    if(s[i] == '1') zero = true;
    s[i]--;
    se.insert(s[i]);
  }

  int x = 0;
  if(se.size() == 3)
  {
    for(int i=0;i<v.size();i++)
    {
      if(s[v[i]] == '1') x ^= 1;
      // t(s[v[i]],v[i],x);
    }
  }
  else if(se.size() == 2)
  {
    for(int i=0;i<v.size();i++)
    {
      if(s[v[i]] != '0') x ^= s[v[i]]-'0';
    }
    if(!zero) 
    {
      cout << 1 << endl;
      return 0;
    }
  }
  else 
  {
    if(s.size() == 1) cout << (char)(s[0]+1) << endl;
    else cout << 0 << endl;
    return 0;
  }

  cout << x << endl;
  return 0;
}
