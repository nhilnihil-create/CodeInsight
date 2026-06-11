#include <iostream> 
 
using namespace std; 
 
int main(){ 
	int n;
	cin >> n;
	int a[n], b[n], c[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	for(int i = 1; i < n; i++){
		cin >> c[i];
	}
	
	int pre_num = -100;
	int satisfaction = 0;
	for(int i = 0; i < n; i++){
		int dish_num = a[i]-1;
		satisfaction += b[dish_num];
		if(dish_num == pre_num+1) satisfaction += c[dish_num];
		pre_num = dish_num;
	}
	cout << satisfaction << endl;
	return 0;
}
