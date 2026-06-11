#include <iostream>
#include <cmath>
using namespace std;

int p[100000];
int c , n;
bool check(int x){
	for(int i = 0;i < 100000;i++){
		if(p[i] == 0)return true;
		if(x % p[i] ==0)return false;
	}
	return true;
}

void set(){
	p[0] = 2;
	c = 1;
	for(int i = 3;i < 123456 * 2;i+=2){
		if(check(i)){
			p[c] = i;
			c++;
		}
	}
}
bool input(){
	cin >> n;
	return n !=0;
}

int find(int num){
		if(num == 1)return -1;
		int u = c;
		int l = 0;
		int x;
		while(u - l> 1){
			x = floor((u + l)/2);
			if(num < p[x]) u = x;
			else if(p[x] < num)l = x;
			else if(p[x] == num){
				//	cout << l << ' '<< p  <<endl;
					return x;
			}
		//cout << p[l] << ' ' << p[u] << endl;
		}
		return l;
}
int find2(int num){
		int u = c;
		int l = 0;
		int x;
		while(u - l > 1){
			x = floor((u + l)/2);
			if(num < p[x]) u = x;
			else if(p[x] < num)l = x;
			else if(p[x] == num)return x;
		}
		return u;
}

void solve(){
	int a = find(n);
	int b = find2(2*n);
	//cout << b << ' ' << a  <<endl;
	cout << b - a - 1<< endl;
}
int main(){
	set();
//	for(int i = 0; p[i] != 0;i++)cout << p[i] << endl;
//	cout << c <<endl;
	while(input())solve();
	 
}

