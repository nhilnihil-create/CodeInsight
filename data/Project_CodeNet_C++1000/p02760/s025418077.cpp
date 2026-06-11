#include <iostream>

using namespace std;

int number[9];
bool open[9];

int zahyou(int i, int j){
	int wakaru = 3 * i + j;
	return wakaru;
}

int main(){
	for(int i = 0; i < 9; i++){
		cin >> number[i];
		open[i] = false;
	}

	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;

		for(int f = 0; f < 9; f++){
			if(number[f] == tmp)
				open[f] = true;
		}
	}

	bool bingostat = false;

//列ビンゴ
	for(int i = 0; i < 3; i++){
		if(open[zahyou(i, 0)] && open[zahyou(i, 1)] && open[zahyou(i, 2)])
			bingostat = true;
	}

//行ビンゴ
	for(int i = 0; i < 3; i++){
		if(open[zahyou(0, i)] && open[zahyou(1, i)] && open[zahyou(2, i)])
			bingostat = true;
	}

//斜めビンゴ
	if(open[zahyou(0, 0)] && open[zahyou(1, 1)] && open[zahyou(2, 2)])
		bingostat = true;
	else if(open[zahyou(0, 2)] && open[zahyou(1, 1)] && open[zahyou(2, 0)])
		bingostat = true;

	if(bingostat)
		cout << "Yes";
	else
		cout << "No";
}