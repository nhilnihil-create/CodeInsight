#include <iostream>
using namespace std;

int p[300001];

void init(int n){
	for(int i = 0 ; i <= 300000 ; i++)
		p[i] = 1;
	p[0] = p[1] = 0;
	
	for(int i = 2 ; i*i <= n ; i++)
		if(p[i] == 1)
			for(int j = i*i ; j <= n ; j += i)
				p[j] = 0;
}
int main(){
	init(300000);
	for(int i = 1 ; i <= 300000 ; i++)
		p[i] += p[i-1];
	int n;
	while(cin >> n , n){
		int ans = 0;
		cout << p[2*n] - p[n] << endl;
	}
}