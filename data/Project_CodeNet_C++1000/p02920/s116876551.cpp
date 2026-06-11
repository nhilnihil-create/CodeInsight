/*
TASK: AGC143 - F - Many Slimes
LANG: C++
NAME: picolylamine
*/
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

#define N_MAX 20
#define S_MAX 300000 // >262144

int N, tail;
long long int table[S_MAX], make_table[N_MAX][S_MAX];

void calc()
{
	if (1 != table[tail - 1]){
		printf("No");
		return;
	}

	for (int i = 0; i < N_MAX; i++){
		fill(make_table[i], make_table[i] + S_MAX, 0);
	}

	make_table[0][tail - 1] = 1;
	for (int i = 1; i <= N; i++){
		make_table[i][tail - 1] = 1;
		long long int carry = 0;
		for (int j = tail - 2; j >= 0; j--){
			make_table[i][j] = make_table[i - 1][j + 1] + make_table[i - 1][j] + carry;
			if (make_table[i][j] > table[j]){
				carry = make_table[i][j] - table[j];
				make_table[i][j] = table[j];
			}
			else{
				carry = 0;
			}
		}
		if (0 != carry){
			printf("No");
			return;
		}
	}

	for (int i = 0; i < tail; i++){
		if (table[i] != make_table[N][i]){
			printf("No");
			return;
		}
	}

	printf("Yes");

	return;
}

int main()
{
	FILE *fin = NULL, *fout = NULL;
	//fin = freopen("input.txt", "r", stdin);
	//fout = freopen("output.txt", "w", stdout);

	scanf("%d", &N);
	int size = pow(2,N), S[S_MAX];
	for (int i = 0; i < size; i++){
		scanf("%d", S + i);
	}

	sort(S, S + size);

	fill(table, table + S_MAX, 0);
	int cur = S[0];
	tail = 0;
	for (int i = 0; i < size; i++){
		if (cur != S[i]){
			tail++;
			cur = S[i];
		}
		table[tail]++;
	}

	tail++;
	calc();

	//finalize
	if (NULL != fin) fclose(fin);
	if (NULL != fout) fclose(fout);

	return 0;
}