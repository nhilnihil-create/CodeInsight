#include <bits/stdc++.h>
 using namespace std;
 
int main()
{
	int N;
	cin >> N;
 
	float tot = 0;
	for(int i=0;i<N;i++){
		double At;
		cin >> At;
		tot += (1.0 / At);
	}
 
	cout << 1.0 / tot ;
 return 0;
}