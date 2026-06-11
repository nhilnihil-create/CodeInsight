// AtCoder_178E.
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define FIO         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(v)      v.begin(), v.end()
#define PB          push_back
#define MP          make_pair
#define UB          upper_bound
#define LB          lower_bound
#define PI          2*acos(0.0)
#define MOD         1000000007
#define GCD(a, b)   __gcd(a, b)
#define LCM(a, b)   ((a)*(b)) / GCD(a, b)
#define INPUT       freopen("input.txt", "r", stdin);
#define OUTPUT      freopen("output.txt", "w", stdout);
#define PRINT(a)    for(auto i : a) cout << i << " "; cout << endl;
#define PRINTS(s)   for(auto i=s.begin(); i!=s.end(); i++) cout << *i << " "; cout << endl;
#define PRINTM(m)   for(auto i=m.begin(); i!=m.end(); i++) cout << i->first << " " << i->second << endl;

int month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
string lowerCase = "abcdefghijklmnopqrstuvwxyz";
string upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

/// Graph moves
const int fxKing[] = {+1,+1,+0,-1,-1,-1,+0,+1}; /// King's move
const int fyKing[] = {+0,+1,+1,+1,+0,-1,-1,-1}; /// King's move
const int fxKnight[] = {+2,+1,-1,-2,-2,-1,+1,+2}; /// Knight's move
const int fyKnight[] = {+1,+2,+2,+1,-1,-2,-2,-1}; /// Knight's move

pair <ll, ll> p[200000];

bool comp(pair<ll,ll>l, pair<ll,ll>r)
{
    if(l.second == r.second)
        return l.first < r.first;
    else return l.second < r.second;
}

int main()
{
    FIO;
    ll n;
    int t = 1;
//    cin >> t;
    while(t--)
    {
        cin >> n;
        ll mn = INT_MAX, mx = INT_MIN;
        ll MN = INT_MAX, MX = INT_MIN;
        for(int i=0; i<n; i++){
            cin >> p[i].first >> p[i].second;
            ll tot = p[i].first + p[i].second;
            if(tot < mn) mn = tot;
            if(tot > mx) mx = tot;
            tot = p[i].first - p[i].second;
            if(tot < MN) MN = tot;
            if(tot > MX) MX = tot;
        }
        cout << max(abs(mx-mn), abs(MX-MN)) << endl;
    }

    return 0;
}
