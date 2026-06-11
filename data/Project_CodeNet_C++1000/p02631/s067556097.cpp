#include<bits/stdc++.h>
using namespace std;

#define ran 202202

int n;
int a[ran];

int main() {
	int s = 0;
	
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
		s ^= a[i];
	}
	for(int i=0;i<n;i++)
		printf("%d%c", s^a[i], i<n-1?' ':'\n');
	
	return 0;
}