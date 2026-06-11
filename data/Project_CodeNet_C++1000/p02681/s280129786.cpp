#include<iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <stdio.h>
using namespace std;
 
int main(){
    string A, B;
    cin>> A>>B;
	int length = (int)(A.length());
  	string B2 = B.substr(0,length);
    if (A==B2) cout << "Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}