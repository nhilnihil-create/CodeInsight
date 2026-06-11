#include <iostream>
using namespace std;

int main()
{
  int h, n, cnt = 0;
  cin >> h >> n;
  
  do
  {
    int a;
    cin >> a;
    h -= a;
    cnt++;
  }while(h > 0 && cnt < n);
  cout << (h <= 0 ? "Yes" : "No") << endl;
  return 0;
}