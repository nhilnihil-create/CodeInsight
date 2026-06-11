#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<queue>
using namespace std;
#define int long long
#define pii pair <int, int>
#define XX first
#define YY second

// constants:
const int mn = 200005;
const int mod = 1000000007;
const long long inf = 4444444444444444444;
const int sminf = 1111111111;
const bool is_multitest = 0;
const bool is_interactive = 0;

// i/o methods:
const bool input_from_file = 0;
const bool output_to_file = 0;
#define filename ""
#define in_extension "inp"
#define out_extension "out"

// data preprocessing: (e.g.: divisor generating, prime sieve)
void preprocess()
{
    
}

// global variables:
int n, p;
string s;
vector <int> md = {0}; //md[i] - mod cua xau tao boi i chu so dau tien cho p
int cnt[10005];

int powmod(int u, int v) {
    if (v == 0) return 1;
    int mid = powmod(u, v/2);
    mid = (mid*mid)%p;
    if (v%2==0) return mid;
    else return (mid*u)%p;
}
// main solution goes here:
void execute(int test_number)
{
    cin>>n>>p>>s;
    if (p == 2 || p == 5) {
        int ans = 0;
        for (int i=0; i<n; i++) if ((s[i] - '0') % p == 0) ans += i+1;
        cout<<ans;
    } else {
        for (int i=0; i<n; i++) md.push_back((md.back() + (s[i]-'0')*powmod(10, n-i))%p);
        int ans = 0;
        for (int i: md) {
            ans += cnt[i];
            cnt[i] ++;
        }
        cout<<ans;
    }
}
// REMEMBER TO CHOOSE TEST METHODS
// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Solution by low_



















signed main()
{
#ifdef lowie
    if (!is_interactive)
    {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
#else
    if (input_from_file) freopen(filename"."in_extension, "r", stdin);
    if (output_to_file) freopen(filename"."out_extension, "w", stdout);
#endif
    if (!is_interactive)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    preprocess();
    int ntest;
    if (is_multitest) cin >> ntest;
    else ntest = 1;

    for (int testno = 1; testno <= ntest; testno++)
    // use for instead of while to serve facebook hacker cup test format
    {
        execute(testno); // only start coding in this function, not in main
    }
}
// Template by low_
// Contact me via mail: ttuandung1803@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie.exe/