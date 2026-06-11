#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define lll __int128
#define ull unsigned long long
#define fi first
#define se second
#define db double
#define ld long double
#define lld __float128

/// order_of_key, find_by_order

template<class T, class COMP>
using custom_set = tree<T, null_type, COMP, rb_tree_tag, tree_order_statistics_node_update>;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class T, class U>
using ordered_map = tree<T, U, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rnd_64(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
    int n; cin >> n;
    string name[n];
    int dat[n];
    for(int i = 0; i < n; i++)
    {
        cin >> name[i] >> dat[i];
    }
    string s; cin >> s;
    int sum = 0;
    for(int i = n-1; i >= 0; i--)
    {
        if(name[i] == s)
            break;
        sum += dat[i];
    }
    cout << sum << '\n';
}






































/// shche ne vmerla Ykraina
