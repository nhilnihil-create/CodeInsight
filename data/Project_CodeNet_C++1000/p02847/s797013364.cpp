#include <iostream>

using namespace std;

int main()
{
  string a;
  cin >> a;
    if(a=="SUN") cout << "7";
    else if(a=="SAT") cout << "1";
    else if(a=="FRI") cout << "2";
    else if(a=="THU") cout << "3";
    else if(a=="WED") cout << "4";
    else if(a=="TUE") cout << "5";
    else if(a=="MON") cout << "6";
  cout << endl;
  return 0;
}
