#include <iostream>
using namespace std;

int main(){
	int matchCount = 0;
	int inputCount;
	int pointSumA[5] = {0}, pointSumB[5] = {0};
	
	while(cin >> inputCount){
		//cout << inputCount << endl;
		if (!inputCount) break;
		
		int cnt = 0;
		while (cnt++ < inputCount){
			int tempA, tempB;
			cin >> tempA >> tempB;
			if (tempA > tempB){
				pointSumA[matchCount] += (tempA + tempB);
			} else if (tempA == tempB) {
				pointSumA[matchCount] += tempA;
				pointSumB[matchCount] += tempA;
			} else {
				pointSumB[matchCount] += (tempA + tempB);
			}
		}
		matchCount++;
	}
	int cnt2 = 0;
	while(cnt2 < matchCount){
		cout << pointSumA[cnt2++] << " " << pointSumB[cnt2] << endl;
	}
	return 0;
}