// class point	の練習（クラスの高度な実装）
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>

typedef long long llong;
using namespace std;


struct Pair {
	char ch;
	int num;
};

int main() {
	Pair chList[130];
	char get_str[1300];


	for (int i = 0; i < 128; i++) {
		chList[i].ch = i;
		chList[i].num = 0;
	}

	while (fgets(get_str, 1300, stdin)) {
		for (int i = 0; get_str[i] != '\0'; i++) {
			chList[get_str[i]].num++;
		}
	}


	for (int i = 65; i <= 90; i++) {
		chList[i + 32].num += chList[i].num;
	}
	for (int i = 97; i <= 122; i++) {
		cout << chList[i].ch << " : " << chList[i].num << endl;
	}
	return 0;
}

