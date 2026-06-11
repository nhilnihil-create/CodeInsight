#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
int main(){
  long double pi =3.14159265358979323846;
  long long int A,B,H,M;
  long double x;
  cin>>A>>B>>H>>M;
  
  x=A*A+B*B-2.0*A*B*cos(abs(H*2*pi/12.0+pi*M/360.0-M*pi/30.0));
  cout<<setprecision(12)<<sqrt(x)<<endl;
}



