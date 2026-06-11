#include<iostream>
using namespace std;

int main(){
	int n, r, p, c;
	int card[50], tmp;

	
	while(cin >> n >> r){
		if(n ==0 && r == 0)
			break;

		for(int i=0; i<n; i++){
			card[i] = n-i;
		}

		for(int i=0; i<r; i++){
			cin >> p >> c;

			for(int j=0; j<c; j++){
				tmp = card[p-1+j];
				for(int k=p-2+j; k>=j; k--){
					card[k+1] = card[k];
				}
				card[j] = tmp;
			}
		}
	cout << card[0]  << "\n";
	}
	return 0;
}