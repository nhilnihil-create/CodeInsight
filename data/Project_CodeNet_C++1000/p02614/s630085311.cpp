#include<iostream>
#include<vector>
#include<string>
#include<bitset>

using namespace std;

int main() {
	int h, w, k;
	cin >> h >> w >> k;
	vector<vector<char>> data(h, vector<char>(w));
	for (int i = 0; i < h; i++) 
		for (int j = 0; j < w ; j++)
			cin >> data[i][j];

	int number_answer = 0;
	for (int i = 0; i < (1 << h + w); i++) {
		int number_black = 0;
		for (int x = 0; x < w; x++)
			for (int y = 0; y < h; y++)
				if ((((i >> x) & 1) == 0) && (((i >> (y + w)) & 1) == 0) && (data[y][x] == '#'))
					number_black++;
	//	cout << number_black <<" i="<<i<< endl; 確認用
		if (number_black == k)
			number_answer++;
	}
	cout << number_answer << endl;

	return 0;
}