#include <iostream>

using namespace std;


int main(){ 
	int n;
	cin >> n;
	int stu[n];
	for(int i = 0; i < n; i++) cin >> stu[i];
	
	int num[n];
	for(int i = 0; i < n; i++) num[stu[i]-1] = i+1;
	for(int i = 0; i < n; i++) cout << num[i] << " ";
	cout << endl;
	return 0;
}
