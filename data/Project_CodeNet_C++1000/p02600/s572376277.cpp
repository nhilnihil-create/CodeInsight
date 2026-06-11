#include <bits/stdc++.h>
using namespace std;
int main(){
	int x,r=1;
  	cin >> x;
  	if(x <= 599) r=8;
  	else if(x >= 600 && x <= 799) r=7;
  	else if(x >= 800 && x <= 999) r=6;
  	else if(x >= 1000 && x <= 1199) r=5;
  	else if(x >= 1200 && x <= 1399) r=4;
  	else if(x >= 1400 && x <= 1599) r=3;
  	else if(x >= 1600 && x <= 1799) r=2;
  	cout << r << endl;
  	return 0;
}