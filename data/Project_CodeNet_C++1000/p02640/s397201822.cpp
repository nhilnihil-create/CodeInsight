#include <iostream>
#include <vector>
#include<string>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
	int X;
	int Y;
	cin >> X >> Y;
	int two_Leg = X * 2;
	int four_Leg = X * 4;
	
	if(Y % 2 != 0){
		std::cout << "No" << endl; 	
		return 0;
	}
	
	if(two_Leg <= Y && four_Leg >= Y){
		std::cout << "Yes" << endl; 	
		return 0;
	}else{
		std::cout << "No" << endl; 	
		return 0;
	}
	
}
