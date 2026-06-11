#include <iostream>
#include <vector>

using namespace std;

int main()
{
  long N, count;
  vector<long> V;
  cin>>N;
  while(N--)
  {
    cin>>count;
    V.push_back(count);
  }
  count = 0;
  for(long i=0;i<V.size();i+=2)
  {
     if(V[i]&1) count++;
  }
  cout << count;
  
  return 0;
}
