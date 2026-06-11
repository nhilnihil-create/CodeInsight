#include<bits/stdc++.h>
using namespace std;
int M, D, cont;
int main() {
	cin>>M>>D;
	for(int i = 1; i <= M; i++) {
		for(int j = 1; j <= D; j++) {
			int d1 = j % 10, d10 = j / 10;
			if(d1 >= 2 && d10 >= 2 && d1 * d10 == i)	cont++;
		}
	}
	cout<<cont<<endl;
	return 0;
}