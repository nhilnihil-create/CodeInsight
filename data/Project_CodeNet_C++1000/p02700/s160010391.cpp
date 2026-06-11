#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
double h1,s1,h2,s2;
cin>>h1>>s1>>h2>>s2;

if(ceil(h2/s1) <= ceil(h1/s2))
    cout<<"Yes";
else
    cout<<"No";
}