#include <iostream>
using namespace std;

int counter(int n, int s,int a){
	if(n == 1)
		if(0 <= s && s <= a){
			return 1;
		} else {
			return 0;
		};
	if(n == 0) return 0;
	int max = a;
	int count = 0;
	for(int j = 1; j <= a; j++){
		if(s - j >= 0)
			count += counter(n - 1, s - j, j - 1);
	}
	return count;
}
int main(){
	int n,s;
	while(cin >> n >> s){
		if(n == 0 && s == 0) break;
		cout << counter(n, s, 9) << endl;
	}
	return 0;
}