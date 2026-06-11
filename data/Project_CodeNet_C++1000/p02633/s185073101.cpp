#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	int x;
	cin>>x;
	int k=360/gcd(360,x);
	cout<<k;
	return 0;
} 