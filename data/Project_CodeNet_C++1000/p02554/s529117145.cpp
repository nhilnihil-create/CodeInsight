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

const int Maxn = (int)1e5 + 1;
const ld pi = acos(-1);
const int m = (int)1e9 + 7;
const int inf = (int)1e18;

template <class T>
ostream &operator<<(ostream &out, vector<T> &A) {
    fr(i, 0, (int)A.size()) out << A[i] << " ";
    return out;
}

int32_t main() {
    IOS int Q = 1;
    // cin >> Q;
    while (Q--) {
         int n;
     cin>>n;
    int temp=n;
    int ans1=1,ans2=1;
    int ans=1;
     while(temp--!=0){
         ans1=(ans1*9)%m;
         ans2=(ans2*8)%m;
         ans=(ans*10)%m;
         
     }
     int a=(ans-(2*ans1)%m)%m;
    a=(a+ans2)%m;
     cout<<(a+m)%m<<endl;
     
    }
    return 0;
}
