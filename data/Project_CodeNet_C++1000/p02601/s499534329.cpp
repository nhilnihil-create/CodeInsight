#include<bits/stdc++.h>

using namespace std;
int main(){
  int a,b,c;
  cin>> a>>b>>c;
  int n;
  cin >> n;
  int x = 0;
  for(int i = 0;i< n;i++)
  {
    
    if(a<b)
    {
      break;
    }
    b*=2;
    x++;
  }
  bool ans = false;
  for(int i = 0;i< n-x;i++)
  {
    c*=2;
    if(a<b&&b<c)
    {
      ans = true;
    }
  }
  if(ans == true)
  {
    cout << "Yes" << endl;
  }
  else 
  {
    cout << "No" << endl;
  }
}
  
