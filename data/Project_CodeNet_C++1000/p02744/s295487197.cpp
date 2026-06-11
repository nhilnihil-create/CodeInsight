#include <bits/stdc++.h>
typedef long long ll; 
const ll mod = 1e9+7;
#define fo(i, n) for (int i = 0; i < n; i++)
#define sc(n) scanf("%d", &n) 
using namespace std;

int n;
int w[10];
int counts[11];
int numDiff;

void printWord() {
    fo(i, n) printf("%c", 'a'+w[i]);
    printf("\n");
}

int max() {
    int ans = w[0];
    fo(i, n) ans = max(ans, w[i]);
    return ans;
}

int increment() {
    if (w[n-1] != n-1) {
        counts[w[n-1]]--; 
        if (!counts[w[n-1]]) numDiff--;
        w[n-1]++;
        if (!counts[w[n-1]]) numDiff++;
        counts[w[n-1]]++;
    }
    else {
        int notLast = n-1;
        while (w[notLast] == n-1) {
            w[notLast] = 0;
            notLast--;
        }
        counts[n-1] -= n-notLast-1;
        if (!counts[n-1]) numDiff--;
        counts[0] += n-notLast-1;
        counts[w[notLast]]--;
        if (!counts[w[notLast]]) numDiff--;
        w[notLast]++;
        if (!counts[w[notLast]]) numDiff++;
        counts[w[notLast]]++;
    }
}

bool orderingRight() {
    int cur = 0;
    fo(i, n) {
        if (w[i] > cur) return false;
        else if (w[i] == cur) cur++;
    }
    return true;
}

bool good() {
    return max() < numDiff && orderingRight();
}

void solve() {
    cin >> n;
    fo(i, n) w[i] = 0;
    fo(i, n) counts[i] = 0;
    counts[0] = n;
    numDiff = 1;
    while (w[n-1] != n-1) {
        printWord();
        // manipulate
        increment();
        while (!good()) increment();
    }
    printWord();
}

int main() {
    int t = 1;
    //scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}