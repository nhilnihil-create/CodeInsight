#include <iostream>
#include <iomanip>
#include <cmath>
#define ll long long int
using namespace std;

int main(int argc, char const* argv[])
{
	int n;
	cin >> n;
	cout << setprecision(15);
	while(n != 0){
			ll sum = 0;
			ll sum2 = 0;
			for(int i = 0; i < n; i++){
					int a;
					cin >> a;
					sum += a;
					sum2 += a * a;
			}
			cout << sqrt(((double)sum2)/n - ((double)sum * sum)/((double)n*n)) << endl;
			cin >> n;
	}
	return 0;
}

