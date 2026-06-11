#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int calc(int i, int count,int sum){
	if (count == 0){
		if (sum == i){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		int count2 = 0;
		for (int j = 0; j < 10; j++){
			count2+=calc(i, count - 1, sum + j);
		}
		return count2;
	}

}

int main(){
	int i;
	while (cin >> i){
		cout << calc(i, 4, 0) << endl;
	}
	return 0;
}