#include<iostream>
using namespace std;

int main(){
	int x[10010];
	int i = 0, i2, i3 = 0, a;
	cin >> a;
	while (i < a){
		cin >> x[i];
		i2 = i;
		i++;
	}
	while (i2 > i3){
		cout << x[i2] << " ";
		i2--;
	}
	cout << x[i3] << endl;
	return 0;
}