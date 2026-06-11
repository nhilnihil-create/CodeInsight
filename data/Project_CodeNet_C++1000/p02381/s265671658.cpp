#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main() {
	int a;
	while (cin >> a) {
	    if (a == 0) break;
	    double b = 0, c = 0, x[a];
    	for (int i = 0; i < a; i++) {
	        cin >> x[i];
	        b += x[i];
	    }
	    b = b / a;
	    for (int i = 0; i < a; i++) {
	        c += pow((x[i] - b), 2);
	    }
	    c = sqrt(c / a);
	    printf("%.6f", c);
	    cout << endl;
	}
}

