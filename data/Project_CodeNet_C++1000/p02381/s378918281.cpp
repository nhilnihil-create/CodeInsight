#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int n;
  int s[1000];
  double E_x,E_x2;

  while(1){
    cin >> n;
    if(n==0)
      break;
    for(int i=0;i<n;i++)
      cin >> s[i];

    E_x=0;
    E_x2=0;
    for(int i=0;i<n;i++)
      {
	E_x+=s[i];
	E_x2+=s[i]*s[i];
      }
    E_x/=n;
    E_x2/=n;
    cout.precision(10);
    cout.setf(ios::fixed);
    cout << sqrt(E_x2-E_x*E_x) << endl;

  }
  return 0;
}