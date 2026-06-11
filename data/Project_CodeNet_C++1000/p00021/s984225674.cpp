#include <iostream>
using namespace std;

int main(){
	int n;
	float x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		float s1 = (y2 - y1) / (x2 - x1);
		float s2 = (y4 - y3) / (x4 - x3);
		if(s1 == s2){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
	return 0;
}