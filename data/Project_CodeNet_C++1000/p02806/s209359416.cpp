#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

int main() {
	int n, l, y=0;
	cin >> n;
    string s[n], f;
    int a[n];
    for(int i=0; i<n; i++) {
        cin >> s[i];
        cin >> a[i];
    }
    cin >> f;
    for(int i=0; i<n; i++) {
        if(strcmp(s[i].c_str(), f.c_str()) == 0) {
        	l=i+1;
            break;
        }
    }
    for(int i=l; i<n; i++) y+= a[i];
    cout << y << endl;
}