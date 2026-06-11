#include <iostream>

using namespace std;

int main(){
	int num, max;
	int list[100] = {0};
	
	max = 0;

	while (cin >> num){
		list[num - 1]++;
	}
	for (int i = 0; i < 100; i++){
		if (max < list[i]){
			max = list[i];
		}
	}
	for (int j = 0; j < 100; j++){
		if (max == list[j]){
			cout << j + 1 << endl;
		}
	}
	return 0;
}