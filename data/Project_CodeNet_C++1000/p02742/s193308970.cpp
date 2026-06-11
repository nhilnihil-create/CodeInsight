#include <bits/stdc++.h>
using namespace std;

int main(){
	long long w, h;
	long long w1,w2,h1,h2;
	cin >> w >> h;	
	
	
	if(h==1 || w==1){
		cout << 1 << "\n";	
	}else{
		w1 = (w%2) ? (w/2)+1 : (w/2);
		w2 = w-w1;
		h1 = (h%2) ? (h/2)+1 : (h/2);
		h2 = h-h1;
		
		cout << (w1*h1)+(w2*h2) << "\n";
	}
}

