#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>

using namespace std;

vector<int> num;

int main() {
	
	int n;
	
	while( cin >> n ) {
		
	if( n == 0 )
	break;	
		
	int score;
	double sum = 0, a2 = 0;
		
	num.clear();
	
	for(int i=0;i<n;i++) {
		
		cin >> score;
		num.push_back(score);
		
		sum += score;
		
	}
	
		sum /= n;
	
		for(int i=0;i<n;i++)
		a2 += pow( num[i] - sum, 2) ; 
			
		cout << fixed << setprecision(8) << sqrt ( a2 / n ) << "\n";
	}
	
	return 0;
}
