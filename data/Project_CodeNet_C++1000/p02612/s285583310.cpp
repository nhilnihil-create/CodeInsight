#include<iostream>
using namespace std;
main()
{
    int a;
cin >> a;
if(a%1000 == 0)
cout << 0 << endl;
else
cout << 1000 - (a%1000) << endl;
}
