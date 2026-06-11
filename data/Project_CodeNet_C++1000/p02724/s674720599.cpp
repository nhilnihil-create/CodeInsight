#include<iostream>
using namespace std;
int main()
{
    long long x;
    cin >> x;
	
  	long long happy=0, y;
  	y = x/500;
    x -= 500*y;
  	happy += 1000*y;
    y = x/5;
    happy += 5*y;
    cout << happy << endl; 
    return 0;
}