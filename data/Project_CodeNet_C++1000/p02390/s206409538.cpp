#include<iostream>
using namespace std;

main(){
int i,j,m,l,n;
cin >> i;
m=i%3600;
l=m%60;
j=(i-m)/3600;
n=(m-l)/60;

cout << j  << ":"<< n << ":" << l << "\n";
}