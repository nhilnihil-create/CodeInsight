#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
	double n,a[1000],sum,sig;
    while(1){
    	sum = 0;
    	sig = 0;
    	cin >> n;
    	if(n == 0) break;
    	for(int i = 0; i < n ; i++){
    		cin >> a[i];
        	sum += a[i];
    	}
    	for(int i = 0; i < n ; i++){
        	sig += pow(a[i]-sum / n,2);
    	}
    	 cout << fixed << setprecision(6)<< sqrt(sig/n) << endl;
    }
    return 0;
}