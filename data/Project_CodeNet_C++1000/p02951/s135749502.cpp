#include <bits/stdc++.h>
using namespace std;

int main()
{
int A,B,C;
cin >>A;
cin >>B;
cin >>C;

if ((B+C-A)<0) {
cout << 0 <<endl;
}
else if (A>=B){    
cout << (B+C-A) << endl;
}
}    