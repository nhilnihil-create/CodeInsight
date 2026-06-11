#include<iostream>
#include<vector>
using namespace std;
int main()
{
	
		int n,a;
		vector<int>number;
		int c[101] = { 0 };
		for (int i = 0; i<100; i++){
			cin >> a;
			c[a]++;
		}
		int max = 1;
		for (int i = 1; i <= 100; i++){ 
			if (max == c[i]){
				number.push_back(i);
			}
			else if (max<c[i]){
				max = c[i];
				number.clear();
				number.push_back(i);
			}
			
		}
		for (int i = 0; i < number.size(); i++){
			cout << number[i] << endl;
		}
}