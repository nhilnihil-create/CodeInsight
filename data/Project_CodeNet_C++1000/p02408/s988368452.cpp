#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int n,n_temp[52];
	char c_temp[53],s[14],h[14],c[14],d[14];
	cin >> n;
	
	for(int i = 0;i < n;i++){
		cin >> c_temp[i] >> n_temp[i];
		if(c_temp[i] == 'S'){
			s[n_temp[i] - 1] = 'S';
		}
		
		if(c_temp[i] == 'H'){
			h[n_temp[i] - 1] = 'H';
		}
		
		if(c_temp[i] == 'C'){
			c[n_temp[i] - 1] = 'C';
			}
		
		if(c_temp[i] == 'D'){
			d[n_temp[i] - 1] = 'D';
			}
	}
	
	for(int i = 0;i < 13;i++){
		if(s[i] != 'S') cout << "S "<< i + 1 << endl;
	}
	
	for(int i = 0;i < 13;i++){
		if(h[i] != 'H') cout << "H " << i + 1 << endl;
	}
	
	for(int i = 0;i < 13;i++){
		if(c[i] != 'C') cout << "C " << i + 1 << endl;
		}
	
	for(int i = 0;i < 13;i++){
		if(d[i] != 'D') cout << "D " << i + 1 << endl;
		}
		
		return 0;			
}