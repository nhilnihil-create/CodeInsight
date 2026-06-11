#include <iostream>
 
using namespace std;
 
int main()
{
	int N;
	cin >> N;
 
	float total = 0;
	for(int i=0;i<N;i++){
		float a;
		cin >> a;
		total += (1.0 / a);
	}
 
	cout << 1.0 / total << endl;
 
}
 