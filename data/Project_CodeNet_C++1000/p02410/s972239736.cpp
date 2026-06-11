#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	int num;
	vector<int> data;
	for(int i = 0; i < m * n; i++){
		cin >> num;
		data.push_back(num);
	}
	vector<int> data2;
	for(int i = 0; i < m; i++){
		cin >> num;
		data2.push_back(num);
	}
	int input = 0;
	for(int i = 0; i < m * n; i++){
		input += data[i] * data2[i%m];
		if(i%m == m-1){
			cout << input << endl;
			input = 0;
		}
	}
			
	return 0;
}