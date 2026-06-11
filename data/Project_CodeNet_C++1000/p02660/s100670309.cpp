#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	long long n, m;
	cin>> n;
	int ans = 0;
	for(long long i=2;i<=n;i++){
		if(n<=i*i){
			ans++;
			break;
		}
		if(n%i==0){
			int ansi = 0;
			while(n%i==0){
				n /= i;
				ansi++;
			}
			int a = (int)sqrt(2*ansi);
			for(int j=0; j<=3;j++){
				if(ansi < (a+j)*(a+j+1)/2){
				ans += a+j-1;
				break;
				}
			}
		}
	}
	cout<< ans <<endl;
}