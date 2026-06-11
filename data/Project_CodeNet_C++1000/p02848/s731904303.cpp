#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define fi first
#define se second
#define pb push_back
 
const int N = 10004;
char s[N];
 
int main() {
    int n;
    scanf("%d\n%s", &n, s);
    int m = strlen(s);
    for (int i = 0; i < m; i++) {
        int c = s[i] - 'A';
        c += n;
        c %= 26;
        s[i] = c + 'A';
    }
    printf("%s", s);
    return 0;
}