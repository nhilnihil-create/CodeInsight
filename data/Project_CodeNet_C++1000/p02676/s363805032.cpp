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
	int K;
	std::string S;
	cin >> K >> S;
	
	if(S.size()>K){
		S = S.substr(0, K) + "...";
	}
	std::cout << S << endl; 
	return 0;
}
