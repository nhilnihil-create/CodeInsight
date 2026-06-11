#include<bits/stdc++.h>
using namespace std;


int main(){
   	int  M, N;
    cin >> M >> N;
	if (1<=M && M <= 9 && 1<= N && N <= 9)
    	cout << M*N << endl;
    else 
    	cout << -1 << endl;
}