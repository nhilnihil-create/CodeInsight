#include <iostream>

using namespace std;

int main(){
  	int X;
  	cin >> X;
  	int i=1;
  	while(360*i % X != 0){
      	i++;
    }
  	cout << 360*i / X << endl;
}