#include<iostream>
using namespace std;
int main(){
double a,c=0;
  	cin >> a;
  	for (int i=0; i<a; i++) {
      double b;
      cin >> b;
      c+=1/b;
    }
  	cout << 1/c;
      
}