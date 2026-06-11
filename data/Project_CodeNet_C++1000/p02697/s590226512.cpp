#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m; cin >> n >> m;
  vector<int> l;
  vector<int> r;
  if (n%2)
  {
    for (int i = 1; i <= n/2; i++)
    {
      l.push_back(i);
    }
    for (int i = n/2+1; i <= n; i++)
    {
      r.push_back(i);
    }
    
  }
 
  if (!(n%2))
  {
    for (int i = 1; i < n/2; i++)
    {
      l.push_back(i);
    }
    for (int i = n/2+1; i <= n; i++)
    {
      r.push_back(i);
    }
    
  }
  
  
  vector<int> a;
  vector<int> b;
 
  vector<int> l1;
  vector<int> l2;
  vector<int> r1;
  vector<int> r2;
 
  if (l.size()%2)
  {
    if((int)l.size() != 1)
    {
      for (int i = 0; i < (int)l.size()/2; i++)
      {
        l1.push_back(l.at(i));
      }
      for (int i = l.size()/2 +1; i < (int)l.size(); i++)
      {
        l2.push_back(l.at(i));
      }
      reverse(l2.begin(),l2.end());
 
    }
    
 
    for (int i = 0; i < (int)r.size()/2; i++)
    {
      r1.push_back(r.at(i));
    }
    for (int i = r.size()/2 ; i < (int)r.size(); i++)
    {
      r2.push_back(r.at(i));
    }
    reverse(r2.begin(),r2.end());
  }
 
  if (!((int)l.size()%2))
  {
    for (int i = 0; i < (int)r.size()/2; i++)
    {
      r1.push_back(r.at(i));
    }
    for (int i = r.size()/2 +1; i < (int)r.size(); i++)
    {
      r2.push_back(r.at(i));
    }
    reverse(r2.begin(),r2.end());
    
    
 
 
    for (int i = 0; i < (int)l.size()/2; i++)
    {
      l1.push_back(l.at(i));
    }
    for (int i = l.size()/2 ; i < (int)l.size(); i++)
    {
      l2.push_back(l.at(i));
    }
    reverse(l2.begin(),l2.end());
  }
  
  for (int i = 0; i < (int)l1.size() && i < (int)l2.size(); i++)
  {
    a.push_back(l1.at(i));
    b.push_back(l2.at(i));
  }
  for (int i = 0; i < (int)r1.size() && i < (int)r2.size(); i++)
  {
    a.push_back(r1.at(i));
    b.push_back(r2.at(i));
  }
 
 
  
 
 
  if (a.size() >= m)
  {
    for (int i = 0; i < m; i++)
    {
      cout << a.at(i) << " " <<  b.at(i) << endl;
    }
 
  }
 
}