#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>	

#define PI 3.14159265359
using namespace std;

int main(){
	double avg, sum;
	int n;
	while (cin >> n && n){
		sum = 0;
		vector<double> s(n);
		for (int i = 0; i < n; i++){
			cin >> s[i];
			sum += s[i];
		}
		avg = sum / n;
		sum = 0;
		for (int i = 0; i < n; i++) sum += (s[i] - avg) * (s[i] - avg);
		cout << fixed << setprecision(9) << sqrt(sum / n) << endl;
	}
}