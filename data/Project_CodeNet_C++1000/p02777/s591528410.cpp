#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back
#define lp(i,s,f) for(ll i = s; i < ll(f); i++)
#define inF freopen("input.in", "r", stdin);
#define outF freopen("output.in", "w", stdout);
#define endl '\n'
#define MOD 1000000007
#define mm(arr) memset(arr, 0, sizeof(arr))

int main(){
    FAST
    string s1, s2, u;
    int n1, n2;
    cin >> s1 >> s2 >> n1 >> n2 >> u;
    if(u == s1)n1--;
    if(u == s2)n2--;
    cout << n1 << " " << n2 << endl;
    return 0;
}
