#include <iostream>
using namespace std;

int main(){
  int x;
	for(int i = 1; i <= 5; i++)
    {cin >> x; if(!x) return cout << i << endl, 0;}
}