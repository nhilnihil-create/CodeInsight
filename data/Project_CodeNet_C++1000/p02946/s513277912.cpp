#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
  int k,n;
  cin >> k >> n;
  
  for(int i=n-(k-1);i<=n+(k-1);i++)
    cout << i << " " ;
}
