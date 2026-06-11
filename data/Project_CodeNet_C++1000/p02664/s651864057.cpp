#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define i128 __int128
#define mp make_pair
#define ld long double
typedef pair<int, int> pii;
typedef priority_queue<int, vector<int>, greater<int> > small_heap;
typedef priority_queue<int> big_heap;
const int N = 1e6 + 100;
int T;
char str[N];

int main() {
    scanf("%s", str + 1);
    int len = strlen(str + 1);
    for (int i = 1; i <= len; i++) {
        if (str[i] == '?')str[i] = 'D';
    }
    printf("%s", str + 1);
    return 0;
}