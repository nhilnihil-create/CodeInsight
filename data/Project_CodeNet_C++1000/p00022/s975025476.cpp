#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
	int Max, Num = 0, In;
	while (true){
		vector<int>	Dat;
		Max = -100000;
		cin >> Num;
		if (Num == 0)break;
		Dat.push_back(-100000);
		for (int i = 0; i < Num; i++){
			cin >> In;
			Dat.push_back(In);
		}
		for (int i = 1; i < Num + 1; i++){
			Dat[i] = max(Dat[i], Dat[i - 1] + Dat[i]);
			Max = max(Max, Dat[i]);
		}
		cout << Max << endl;
	}
	return 0;
}