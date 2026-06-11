#include <bits/stdc++.h>
#define ll long long int
//#define m 1000000007
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp>     //required
// using namespace __gnu_pbds;              //required
// using namespace std;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// ordered_set<int> s;
// ordered_set<int>::iterator itr;
// /* or:
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// ordered_set s;
// This works in C++98 but the above version only works in C++11
// */
// //char str[10000000];
void swap(ll *xp, ll *yp)
{
    ll temp = *xp;
    *xp = *yp;
    *yp = temp;
}
bool vis[10000009] = {0};
vector<ll> vec;
ll dis[10000007] = {0};
ll longSubarrWthSumDivByK(ll arr[],
                          ll n, ll k)
{

    unordered_map<ll, ll> um;

    ll mod_arr[n], max = 0;
    ll curr_sum = 0;

    for (int i = 0; i < n; i++)
    {
        curr_sum += arr[i];

        mod_arr[i] = ((curr_sum % k) + k) % k;
    }

    for (int i = 0; i < n; i++)
    {

        if (mod_arr[i] == 0)

            max = i + 1;

        else if (um.find(mod_arr[i]) == um.end())
            um[mod_arr[i]] = i;

        else
            // if true, then update 'max'
            if (max < (i - um[mod_arr[i]]))
            max = i - um[mod_arr[i]];
    }

    return max;
}
int main()
{
    string str;
    cin >> str;
    cout << str[0] << str[1] << str[2] << "\n";
    return 0;
}