#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

char s[10];

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	scanf("%s", s);
	for (int i = 0; i < 3; i++) {
		if (s[i] == s[i+1]) {
			return printf("Bad"), 0;
		}
	}
	printf("Good");
    return 0;
}
