#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
int n, k;
int fruits[1000];
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++) 
		cin>>fruits[i];
	sort(fruits, fruits+n);
	int price=0;
	for(int i=0;i<k;i++) {
		price+=fruits[i];
	}
	cout<<price<<endl;
	
		
}

