#include <bits/stdc++.h>
using namespace std;

long long w, h, ans=0;

int main() {
	cin >> w >> h;
	if(w%2==0){
		cout << ((w+1)/2)*h << endl;
	}
    else if(h==1 || w==1){
    	cout << 1 << endl;
    }
	else{
		cout << ((w+1)/2)*h - h/2 << endl;
	}
}