#include<iostream>
#include <cstdio>
using namespace std;

const int m_MAX = 50;
const int f_MAX = 50;
const int r_MAX = 100;
int m[m_MAX], f[f_MAX], r[r_MAX];

char scorejudge(int x, int y, int z){
	char scoreX;
	if (x == -1 || y == -1)scoreX = 'F';
	else if (x + y >= 80)scoreX = 'A';
	else if (x + y >= 65)scoreX = 'B';
	else if (x + y >= 50)scoreX = 'C';
	else if (x + y >= 30 && z >= 50)scoreX = 'C';
	else if (x + y >= 30)scoreX = 'D';
	else scoreX = 'F';
	return scoreX;
}

int scoreinput(){
	int i = 0;

	for (;; i++){
		cin >> m[i] >> f[i] >> r[i];
		if (m[i] == -1 && f[i] == -1 && r[i] == -1)break;
	}

	return i;
}

int main(){
	int i=scoreinput();

	for (int j = 0; j < i; j++){
		cout << scorejudge(m[j], f[j], r[j]) << endl;
	}

	return 0;
}
