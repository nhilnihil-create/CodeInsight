#include <iostream>

using namespace std;

int main()
{
  int N;
  int counter = 0;
  cin >> N;
  int a[N];
  for(int i=0;i < N;i++)
  {
    cin >> a[i];
  }
  for(int j = 0;j < N;j++)
  {
    if(a[j] != j+1)
    {
      counter++;
    }
  }
  if(counter <=2)
  {
    cout << "YES" << endl;
  }
  else
  {
     cout << "NO" << endl;
  }
  return 0;
}
