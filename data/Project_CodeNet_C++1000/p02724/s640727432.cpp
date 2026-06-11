#include <bits/stdc++.h>
using namespace std;
int main(){
int x;
cin >> x;
int happiness = 0;
while (x > 5){
if(x >= 500){
	happiness += floor(x / 500) * 1000;
	x = x % 500;
} else {
	happiness += floor(x / 5) * 5;
	x = x % 5;
}
}
cout << happiness << endl;

}


