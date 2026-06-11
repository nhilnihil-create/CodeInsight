#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

int x,n;
vector<int>v{};
cin>>x>>n;
if(!n)
  cout << x;
else
{

  int c;
  for(int i = 0; i < n; i++)
  {
    cin >> c;
    v.push_back(abs(c));
  }

  sort(v.begin(), v.end());
  auto it = find(v.begin(),v.end(), x);
  
  if (it == v.end()){
    cout << x;
   exit(0);
  }
    
 
  int z = 1;

  while(true)
  {

    if(*(it-z) != x-z || x -z==0)
    {
      z = x-z;
      break;
    }
    else if (*(it+z) != x+z)
    {
      z = x+z;
      break;
    }
    z++;
    
  }
  cout << z;
  
}
return 0;
}