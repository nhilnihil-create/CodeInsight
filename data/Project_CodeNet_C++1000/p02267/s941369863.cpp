#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


 
 int main(){
 	int N;
 	int S[100000];
 	int q;
 	int T[1000];
 	int count = 0;

 	cin >> N;
 	for(int i = 0; i < N; i++){
 		cin >> S[i];
 	}
 	cin >> q;
 	for(int j = 0; j < q; j++){
 		cin >> T[j];
 	}

 	for(int j = 0; j < q; j++){
 		int i = 0;
 		S[N] = T[j];
 		while( S[i] != T[j] ) i++;
 		if(i != N) count++;
 		else{count = count + 0;}
 	}

 	cout << count << endl;

 	return 0;
 }