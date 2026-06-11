#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	int n;
	cin>>n;
	long long sum = 0;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(i > 1){
			if(a[i-1] > a[i]){
				sum += a[i-1] - a[i];
				a[i] = a[i-1];
			}
		}
	}
	printf("%lld\n",sum);
	return 0;
}