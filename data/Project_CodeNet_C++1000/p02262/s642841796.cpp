#include <iostream>
#include <cmath>
using namespace std;

int an(int m){
	if(m==1) return 1;
	else{
		return 3*an(m-1) + 1;
	}
}


int main(){
	const int MAX=1000000;
	int arr[MAX], G[MAX];
	int N, cnt = 0;
	cin >> N;
	
	int m = (int)(log(2*N+1)/log(3.0));
	
	for(int i=0; i<m; i++){
		G[m-1-i] = an(i+1);
	}
	
	for(int i=0; i<N; i++){
		cin >> arr[i];
	}
	
	for(int k=0; k<m; k++){
		int g = G[k];
		
		for(int i=g; i<N; i++){
			int v = arr[i];
			int j = i - g;
			while(j >= 0 && arr[j] > v){
				arr[j+g] = arr[j];
				j = j - g;
				cnt++;
			}
			arr[j+g] = v;
		}
	}
	
	cout << m << endl;
	for(int i=0; i<m; i++){
		if(i==0){
			cout << G[i];
		}
		else{
			cout << " " << G[i];
		}
	}
	cout << endl;
	
	cout << cnt << endl;
	
	for(int i=0; i<N; i++){
		cout << arr[i] << endl;
	}
	
}