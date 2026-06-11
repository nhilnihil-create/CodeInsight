#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  
  int a[n],b[n];
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  
  int line[n];
  rep(i,n) line[i] = i+1;
  
  int count = 1;
  int ansa = 0, ansb = 0;
  bool flag = true;
  do{
    rep(i,n)
    {
      if(line[i] != a[i]) flag = false;
    }
    if(flag == true) ansa = count;
    
    flag = true;
    rep(i,n)
    {
      if(line[i] != b[i]) flag = false;  
    }
    if(flag == true) ansb = count;
    
    if(ansa > 0 && ansb > 0) break;
    count++;
    flag = true;
  }while(next_permutation(line,line+n));
  
  cout << abs(ansa - ansb) << endl;
}