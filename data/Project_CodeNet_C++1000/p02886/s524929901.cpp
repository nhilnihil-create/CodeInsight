#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> data(N);
  int sum=0;
  for(int i=0; i<N; i++)
  {
    cin >> data.at(i);
  }
  
  for(int i=0; i<N; i++)
  {
    for(int k=i+1; k<N; k++)
    {
      sum += data[i] * data[k];
      //cout << sum << endl;
    }
  }
  
  cout << sum << endl;
  return 0;
}