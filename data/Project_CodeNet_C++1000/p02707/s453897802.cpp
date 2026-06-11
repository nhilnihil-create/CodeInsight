#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n;cin>>n;
  vector<int> v(n,0);
  
  int temp;
  for(int i=0;i<n-1;++i)
  {
    cin>>temp;
    v[--temp]++;
  }
  
  for(auto i :v) cout<<i<<endl;
}
