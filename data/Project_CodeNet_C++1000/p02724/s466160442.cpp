#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	cin>>n;
	long long hundred = n/500;
	n%=500;
	long long five = n/5;
	cout<<hundred*1000+five*5;
}