#include <bits/stdc++.h>

#define f first
#define s second

#define pb push_back
#define mp make_pair

#define ll long long
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define sz(v) int(v.size())

using namespace std;

const int MAXN = (int) 2e5 + 10;
const int INF = (int) 2e9 + 7;
const ll LINF = (1LL<<62);

int n;

ll a[MAXN];
bool u[MAXN];
ll all;

ll maxSubarrayXOR(ll set[], int n)
{
    // Initialize index of
    // chosen elements
    int index = 0;

    // Traverse through all
    // bits of integer
    // starting from the most
    // significant bit (MSB)
    for (int i = 60; i >= 0; i--)
    {
        // Initialize index of
        // maximum element and
        // the maximum element
        int maxInd = index;
        ll maxEle = -LINF;
        for (int j = index; j < n; j++)
        {
            // If i'th bit of set[j]
            // is set and set[j] is
            // greater than max so far.
            if ( (set[j] & (1LL << i)) != 0
                     && set[j] > maxEle )
                maxEle = set[j], maxInd = j;
        }

        // If there was no
        // element with i'th
        // bit set, move to
        // smaller i
        if (maxEle == -LINF)
        continue;

        // Put maximum element
        // with i'th bit set
        // at index 'index'
        swap(set[index], set[maxInd]);

        // Update maxInd and
        // increment index
        maxInd = index;

        // Do XOR of set[maxIndex]
        // with all numbers having
        // i'th bit as set.
        for (int j=0; j<n; j++)
        {
            // XOR set[maxInd] those
            // numbers which have the
            // i'th bit set
            if (j != maxInd &&
               (set[j] & (1ll << i)) != 0)
                set[j] = set[j] ^ set[maxInd];
        }

        // Increment index of
        // chosen elements
        index++;
    }

    // Final result is
    // XOR of all elements
    ll res = 0;
    for (int i = 0; i < n; i++)
        res ^= set[i];
    return res;
}

void print(ll x) {
    for (int i = 10; i >= 0; i--) cout << (x>>i)%2;
    cout<<endl;
}

ll f(ll x) {
    return x + (all ^ x);
}

int main() {
    #ifdef sony
        freopen("input.txt", "r", stdin);
    #endif // sony

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        all ^= a[i];
    }
    sort(a, a + n);
    for (int i = 60; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if ((all >> i) % 2 && (a[j] >> i) % 2) {
                a[j] -= (1LL << i);
            }
        }
    }
    ll mn = maxSubarrayXOR(a, n);
    cout << f(mn);
    return 0;
}
