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
#define int ll

char missing(char c1, char c2){
    if(c1 < c2)swap(c1, c2);
    if(c1 == 'R' && c2 == 'G'){
        return 'B';
    }
    else if(c1 == 'G' && c2 == 'B'){
        return 'R';
    }
    else{
        return 'G';
    }
}
int32_t main(){
    FAST
    int n; cin >> n;
    string s; cin >> s;
    vector<int> R;
    vector<int> B;
    vector<int> G;
    for(int i = 0; i < n; i++){
        if(s[i] == 'R')R.pb(i);
        else if(s[i] == 'B')B.pb(i);
        else G.pb(i);
    }
    int ans = 0;
    vector<pair<char, int> > vec;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(s[i] != s[j]){
                if(missing(s[j], s[i]) == 'R'){
                    ans += R.size() - (lower_bound(R.begin(), R.end(), j) - R.begin());
                    if(j + j - i >= n)continue;
                    else if(s[j + j - i] == 'R')ans--;
                }
                else if(missing(s[j], s[i]) == 'B'){
                    ans += B.size() - (lower_bound(B.begin(), B.end(), j) - B.begin());
                    if(j + j - i >= n)continue;
                    else if(s[j + j - i] == 'B')ans--;
                }
                else{
                    ans += G.size() - (lower_bound(G.begin(), G.end(), j) - G.begin());
                    if(j + j - i >= n)continue;
                    else if(s[j + j - i] == 'G')ans--;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
