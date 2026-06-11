#include<bits/stdc++.h>
using namespace std;
 
int h1, m1, h2, m2, k;
 
int main(){
	scanf("%d %d %d %d %d", &h1, &m1, &h2, &m2, &k);
	h1 = h1 * 60 + m1;
	h2 = h2 * 60 + m2 - k;
	printf("%d\n", max(0, h2 - h1));
	return 0;
}