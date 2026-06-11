#include <iostream>
#include <iomanip>
using namespace std;
int main(){
		int a,b;
		cin >> a >> b;
		double c = double(a)/double(b);
		cout << a/b << " " << a%b << " " << fixed << setprecision(8) << c << endl;
}