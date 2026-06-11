#include <iostream>
#define ll long long

using namespace std;

int main(){
	ll n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin >>a[i];
	ll max =0;
	ll sum =0;
	for (int i = 0; i < n-1; ++i)
	{
		max = (a[i] >max)?a[i]:max;
		if(max>a[i+1]){
			sum +=(max -a[i+1]);
		}
	}
		 
	cout <<sum ;
	return 0;
}