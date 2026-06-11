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
char str[20];

int main() {
    scanf("%s", str + 1);
    int len = strlen(str + 1);
    if (len & 1) {
        puts("No");
        return 0;
    }
    for (int i = 2; i <= len; i += 2) {
        if (str[i - 1] == 'h' && str[i] == 'i')continue;
        else {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}
