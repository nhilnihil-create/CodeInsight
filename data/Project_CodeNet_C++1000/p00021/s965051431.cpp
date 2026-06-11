#include<iostream>
using namespace std;

int main(){
	int n;
	double x[4];
	double y[4];
	double slope[2];
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2] >> x[3] >> y[3];
		slope[0] = (y[1] - y[0])/(x[1] - x[0]);
		slope[1] = (y[3] - y[2])/(x[3] - x[2]);
		if(slope[0] == slope[1]){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
}