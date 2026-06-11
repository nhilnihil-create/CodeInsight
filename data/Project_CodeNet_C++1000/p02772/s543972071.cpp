#include <iostream>
using namespace std;

int main()
{
  int N;
  int A[1010];
  cin >> N;
  for(int i = 0; i < N; ++i) cin >> A[i];
  
  bool approved = true;
  for(int i = 0; i < N; ++i)
  {
    if(A[i]%2 == 0)
    {
      if(A[i]%3 != 0 && A[i]%5 != 0)
      {
        approved = false;
        break;
      }
    }
  }
  
  if(approved) cout << "APPROVED" << endl;
  else cout << "DENIED" << endl;
}