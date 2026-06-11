#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	string S, T;
	int a, b;
	cin >> S >> T;
	scanf("%d %d", &a, &b);
	string U;
	cin >> U;
	if (U == S) a--;
	if (U == T) b--;
	printf("%d %d\n", a, b);
}