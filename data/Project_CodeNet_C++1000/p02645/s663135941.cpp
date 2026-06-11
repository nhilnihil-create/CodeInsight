#include <iostream>
using namespace std;

int main() {
	char a[22] = {};
  int i=-1;
  do{
  	i++;
    cin >> a[i];
  } while(a[i]);
    for(int i=0; i<3; i++){
    	cout << a[i];
    }
}