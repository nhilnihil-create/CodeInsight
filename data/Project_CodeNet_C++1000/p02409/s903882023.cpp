#include<iostream>
using namespace std;

int main(){
	int n;
	int b = 0, f = 0,r = 0,v = 0;
	int count[4][3][10] ={0};
	
	cin >> n;
	
	for( int i = 0; i < n; i++ ){	
		cin >> b >> f >> r >> v;
		count[b-1][f-1][r-1] += v;
	}
	
	for( int b = 0; b < 4; b++ ){
		for ( int f = 0; f < 3; f++ ){
			for ( int r = 0; r < 10; r++ ){
					cout << " " << count[b][f][r];
			}
			cout << endl;
		}
		if (b < 3)
			cout << "####################" << endl;
	}
}