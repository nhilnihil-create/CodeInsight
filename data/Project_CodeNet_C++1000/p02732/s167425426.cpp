#include <bits/stdc++.h>
using namespace std;

#define ipr pair<int, int>
#define pb push_back
#define ff first
#define ss second
#define fr(i, j, k) for (int i = j; i < k; i++)
#define rf(i, j, k) for (int i = j; i >= k; i--)
#define ll unsigned long long
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mp make_pair
#define cnt_ones(x) __builtin_popcountll(x)

#define IOS                           \
    std::ios::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

const int Maxn = (int)1e6;
const ld pi = acos(-1);
const int mod = (int)1e9 + 7;
const int inf = (int)1e18;

template <class T>
ostream &operator<<(ostream &out, vector<T> &A) {
    fr(i, 1, (int)A.size()) out << A[i] + 1 << " ";
    return out;
}

int32_t main() {
    int n;  cin>>n;
    map<int, int > my;
    vector<int > A(n);  fr(i,0,n){
        cin>>A[i];
        my[A[i]]++;
    }
    int ans = 0;
    for(auto x : my){
        ans += x.ss*(x.ss-1)/2;
    }
    fr(i,0,n){
        int ele = my[A[i]];
        int temp = ans - ele*(ele-1)/2;
        ele--;
        temp += ele*(ele-1)/2;
        cout << temp << endl;
    }
    return 0;
}
