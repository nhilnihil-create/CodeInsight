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
	std::string S;
	cin >> N >> S;
	
	int cnt = 1;
	
	for(int i = 0;i<N-1;i++){
		if(S[i] != S[i+1]){
			cnt++;
		}
	}
	
	cout << cnt << endl;
	return 0;
	
}
