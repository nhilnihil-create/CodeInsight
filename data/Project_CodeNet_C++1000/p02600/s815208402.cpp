#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define watch(x) cout << "["<<(#x) << " is " << (x) << "]" << endl
void watchVecI(vector<int>a){
	for(int i = 0; i < a.size(); ++i){
		cout << a[i] << " ";
	}
	cout << endl;
}
void watchVecS(vector<string>a){
	for(int i = 0; i < a.size(); ++i){
		cout << a[i] << " ";
	}
	cout << endl;
}
long double binets(double n){
	long double first = (1+sqrt(5.0))/2.0;
	long double second = (1-sqrt(5.0))/2.0;
	long double third = pow(first,n)-pow(second,n);
	return (third/sqrt(5.0));
}



void solve(){
	int n;
	cin >> n;
	if(n>=400&&n<=599){
		cout << 8 << endl;
		return;
	}
	if(n>=600&&n<=799){
		cout << 7 << endl;
		return;
	}
	if(n>=800&&n<=999){
		cout << 6 << endl;
		return;
	}
	if(n>=1000&&n<=1199){
		cout << 5 << endl;
		return;
	}
	if(n>=1200&&n<=1399){
		cout << 4 << endl;
		return;
	}
	if(n>=1400&&n<=1599){
		cout << 3 << endl;
		return;
	}
	if(n>=1600&&n<=1799){
		cout << 2 << endl;
		return;
	}
	if(n>=1800&&n<=1999){
		cout << 1 << endl;
		return;
	}
}


int main(){
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}