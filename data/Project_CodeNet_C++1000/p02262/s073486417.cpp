#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

long long cnt;
int R[1000000];
int n;
vector<int> G;

void insertionSort(int R[],int n,int g){
	int key;
	int j;
	for (int i = g; i < n; i++){
		key = R[i];
		j = i - g;
		while (j >= 0 && R[j] > key){
			R[j + g] = R[j];
			j -= g;
			cnt++;
		}
		R[j + g] = key;
	}
}

void shellSort(int R[], int n){
	for (int h = 1; ; ){
		if (h > n){
			break;
		}
		G.push_back(h);
		h = 3 * h + 1;
	}
	for (int i = G.size() - 1; i >= 0; i--){
		insertionSort(R, n, G[i]);
	}
}

int main(){
	cin >> n;
	int j;
	for (int i = 0; i < n; i++){
		scanf("%d",&R[i]);
	}
	int key;
	cnt = 0;
	shellSort(R, n);
	cout << G.size() << endl;
	for (int i = G.size()-1; i >= 0; i--){
		printf("%d",G[i]);
		if (i != 0)
			printf(" ");
	}
	printf("\n");
	printf("%d\n", cnt);
	for (int i = 0; i < n; i++){
		printf("%d\n",R[i]);
	}
}