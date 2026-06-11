#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	while(true){
		int n,r;
		cin >> n >> r;
		if (n == 0 && r == 0) break;
		int cards[2][n];
		for (int i=0;i<n;++i){
			cards[0][i] = n-i;
			cards[1][i] = n-i;
		}
		for (int i=0;i<r;++i){
			int f = i%2;
			int t = (i+1)%2;
			int p,c;
			cin >> p >> c;
			for (int l=0;l<p-1;++l){
				cards[t][l+c] = cards[f][l];
			}
			for (int l=p-1;l<p+c-1;++l){
				cards[t][l-(p-1)] = cards[f][l];
			}
			for (int l=p+c-1;l<n;++l){
				cards[t][l] = cards[f][l];
			}
		}
		int t = r%2;
		cout << cards[t][0] << endl;

	}
	return 0;
}