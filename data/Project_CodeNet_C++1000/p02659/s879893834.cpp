#include<iostream>
using namespace std;

int main()
{
 long int A;
 double B;
 cin >> A >> B;
 long int B_ = 100*B+0.5;
 cout << A*B_/100 << endl;
 return 0;
}