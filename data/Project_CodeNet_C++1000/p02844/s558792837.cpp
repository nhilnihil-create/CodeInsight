#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <climits>

using namespace std;


int main(){
	int n;
	cin >> n;

	vector<char> s(n);
	vector<int> arr(n);
	vector<int> answers(1000);
	vector<int> num(1000);

	for (int i = 0; i < n;i++) cin >> s[i];

	for(int i=0;i<n;i++)arr[i]= int(s[i] - '0');

	//数を判定
	int ans = 0;

	for (int i = 0; i < 1000; i++) {
		//iを3桁に変換
		int kurai1 = i / 100;
		int kurai2 = (i-kurai1*100) / 10;
		int kurai3 = i - kurai1 * 100 - kurai2 * 10;
		
		int count1 = 10;
		int count2 = 10;
		int count3 = 10;

		int point1 = 0;
		int point2 = 0;

		//100の位の数があるか
		for (int i = 0; i < n-2; i++) {
			if (arr[i] == kurai1) {
				count1 = arr[i];
				point1 = i;
				break;
			}
		}
		//10の位の数があるか（100の位がなければcontine）
		if (count1 == 10) {
			continue;
		}
		else {
			for (int i = point1 + 1; i < n - 1; i++) {
				if (arr[i] == kurai2) {
					count2 = arr[i];
					point2 = i;
					break;
				}
			}
			
		}

		//1の位の数があるか
		if (count2 == 10) {
			continue;
		}
		else {
			for (int i = point2 + 1; i < n; i++) {
				if (arr[i] == kurai3) {
					ans++;
					break;
				}
			}

		}

	}

	cout << ans << endl;
	

	return 0;
}
