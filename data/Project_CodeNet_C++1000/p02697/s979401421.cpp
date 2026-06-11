#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int n , m;

inline int read(){
	int s = 0 , w = 1;
	char ch = getchar();
	while( (ch < '0') || (ch > '9') ){
		if(ch == '-'){
			w = -1;
		}
		ch = getchar();
    }
   	while( (ch >= '0') && (ch <= '9') ){
   		s = s * 10 + ch - '0';
		ch = getchar();
	}
   	return s * w;
}

int main(){
	
	n = read();
	m = read();
	
	for(int i = n / 2 , j = i + 1 , k = 1 ; k <= m ; k++ , i-- , j++ ){
		if(n % 2 == 0 && (j - i == n / 2 || j - i == n / 2 + 1)){
			j++;
		}
		cout << i << " " << j << endl;
	}

	return 0;
}