#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1e5 + 5;

int n;
int a[N];
map<int, int> freq;
vector<int> v;

bool valid() {
    if(freq[0] == n) return true;
    if(n % 3 != 0) return false;
    if(v.size() == 2) {
        if(freq[0] == n / 3) return true;
        return false;
    }
    if(v.size() == 3) {
        if(freq[v[0]] == (n / 3) && freq[v[1]] == (n / 3) && freq[v[2]] == (n / 3)) {
            if((v[0] ^ v[1] ^ v[2]) == 0) {
                if(v[0] != v[1] && v[0] != v[2] && v[1] != v[2]) return true;
                return false;
            }
            return false;
        }
        return false;
    }
    return false;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        freq[a[i]]++;
        if(freq[a[i]] == 1) v.pb(a[i]);
    }
    if(valid()) printf("Yes\n");
    else printf("No\n");
}