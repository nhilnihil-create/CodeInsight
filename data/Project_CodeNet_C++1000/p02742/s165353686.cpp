#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
long long h,w;
cin >> h >> w;
if(h == 1 || w == 1){
	cout << "1" << '\n';
	}
else if(h % 2 == 0 && w % 2 == 1){
	cout << h * w / 2 << '\n';
	}
else if(h % 2 == 1 && w % 2 == 0){
	cout << h * w / 2 << '\n';
	}
else if(h % 2 == 0 && w % 2 == 0){
	cout << h * w / 2 << '\n';
	}
else if(h % 2 == 1 && w % 2 == 1){
	cout << h * w / 2 + 1 << '\n';
	}
return 0;
}