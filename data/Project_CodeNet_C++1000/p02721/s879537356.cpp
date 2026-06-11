#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define INF 0x3f3f3f3f
const int N=2e5 + 5;
const ll mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL);
    int n, k, c;
    string s;
    cin >> n >> k >> c >> s;
    vector<int> l(k), r(k);
    int i = 0, j = n - 1;
    for(int idx=0;idx<k;idx++) {
        while(s[i] != 'o') i++;
        l[idx] = i;
        i += c + 1;
        while(s[j] != 'o') j--;
        r[k - idx - 1] = j;
        j -= c + 1;
    }
    for(int idx=0;idx<k;idx++) {
        if(l[idx] == r[idx]) cout << l[idx] + 1 << endl;
    }
    return 0;
}
