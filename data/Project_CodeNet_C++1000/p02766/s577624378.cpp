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
	int N;
	int K;
	cin >> N >> K;
	int ans = 0;
	while(N>0){
		N /= K;
		ans++;
	}
	
	std::cout << ans << endl; 
	return 0;
}
