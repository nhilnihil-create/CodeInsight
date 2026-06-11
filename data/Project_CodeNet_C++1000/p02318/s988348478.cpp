#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
//最小の数を探す
int min(int a, int b, int c)
{
	return a > b ? (b > c ? c : b) : (a > c ? c : a);
}

//レーベンシュタイン距離を求める
int LevenshteinDistance(string str1, string str2)
{
	int lenstr1 = str1.length() + 1;
	int lenstr2 = str2.length()+ 1;
	int d[lenstr1][lenstr2];
	int i1 = 0, i2 = 0, cost = 0;

	for (;i1 < lenstr1; i1++) d[i1][0] = i1;
	for (;i2 < lenstr2; i2++) d[0][i2] = i2;

	for (i1 = 1; i1 < lenstr1; i1++) {
		for (i2 = 1; i2 < lenstr2; i2++) {
			cost = str1[i1 - 1] == str2[i2 - 1] ? 0 : 1;
			d[i1][i2] = min(d[i1 - 1][i2] + 1, d[i1][i2 - 1] + 1, d[i1 - 1][i2 - 1] + cost);
		}
	}
	
	return d[lenstr1 - 1][lenstr2 - 1];
}

int main()
{	
	string str1;
	string str2;
	cin>>str1;
	cin>>str2;
	printf("%d\n", LevenshteinDistance(str1, str2));
	return 0;
}