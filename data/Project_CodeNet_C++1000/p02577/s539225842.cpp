#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2e5+5;

char S[N];

int main()
{
	scanf("%s",S);
	int n = strlen(S);
	ll sum = 0;
	for(int i=0;i<n;i++) sum += int(S[i] - '0');
	puts(sum % 9 == 0 ? "Yes" : "No");
}
