#include<bits/stdc++.h>
using namespace std;

int cnt = 0, m;
int G[14] = {1, 4 , 13, 40, 121, 364, 1093, 3280, 9841, 29524, 88573, 265720, 797161, 2391484};
int array[1000005];

void insertionSort(int n, int g){
	int v;
	for(int i = g ; i < n ; i++){
		v = array[i];
		int j = i - g;
		while(j >= 0 && array[j] > v){
			array[j + g] = array[j];
			j -= g;
			cnt++;
		}
		array[j + g] = v;
	}
} 

void shellSort(int n){
	int h;
	for(h = 1 ; ; ){
		if(h > n){
			break;
		}
		
		h = 3 * h + 1;
	}
		
		for(int i = 0 ; i < 14 ; i++){
			if(h == G[i]){
				m = i;
			}
			for(int i = m - 1 ; i >= 0 ; i--){
				insertionSort(n, G[i]);
			}
		}
}

int main(){
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> array[i];
	}
	
	shellSort(n);
	
	cout << m << endl;
	
	for(int i = m - 1 ; i >= 0 ; i--){
		cout << G[i];
		cout << " ";
	}
	
	cout << endl;
	cout << cnt << endl;
	
	for(int i = 0 ; i < n ; i++){
		cout << array[i] << endl;
	}
	
	return 0;
	
}