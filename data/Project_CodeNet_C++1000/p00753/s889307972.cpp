#include <iostream>
#include <algorithm>

#define N 123456

using namespace std;

int main()
{
  int n, cnt;
  bool a[2*N+1];
  fill(a, a+(2*N+1), true);
  a[0] = a[1] = false;

  for(int i = 2; i <= 2*N; i++)
    if(a[i])
      for(int j = i+i; j <= 2*N; j+=i)
	a[j] = false;
  
  while(cin>>n && n){
    cnt = 0;
    for(int i = n+1; i <= 2*n; i++)
      if(a[i]) cnt++;

    cout << cnt << endl;
  }

  return 0;
}