#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define initdp(a, b)  for (int i = 0; i <= a; i++)   for (int j = 0; j <= b; j++) dp[i][j] = -1;
#define fi first
#define se second
#define pb push_back
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define all(arr) arr.begin(), arr.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repd(i, n) for (int i = n - 1; i >= 0; i--)
#define fo(i, l, r) for (int i = l; i <= r; i++)
#define inf 1000000001
#define inf1 1000000000000000001
#define mod 1000000007
#define pie 3.14159265358979323846
#define N 1000005
#define mid(l, r) l + (r - l) / 2
#define vec vector<int>
#define vecl vector<ll>
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define umapi unordered_map<ll, ll>
#define umapc unordered_map<char, int>
#define endl "\n"
#define pui pair<int, pair<int,int> >
using namespace std;



/*
            ॐ
    || Jai Shree Ram ||  
 
 */

void solve(){
    
    int  n;
    cin>>n;

    vec arr(n);

    rep(i,n) {
        cin>>arr[i];
    }
    unordered_map<int,int> mp;
    for(auto it : arr) {
        mp[it]++;
    }
    int ans = 1;
    sort(all(arr));
    if(arr[0] == arr[1]) {
        ans = 0;
    } else {
        ans = 1;
    }
    set<int> st;
    st.insert(arr[0]);

    for(int i=0; i<n; i++) {
        if(mp[arr[i]] == 1) {
            int val = arr[i];
            bool count = true;
            for(int j=1; j<=sqrt(val); j++) {
                if(val%j == 0 ) {
                    int x = val/j;
                    if(st.find(x) != st.end()) {
                        count = false;
                        break;
                    }

                    if(val % x== 0) {
                        if(st.find(val/x) != st.end()) {
                        count = false;
                        break;
                    }
                    }
                }
            }
            st.insert(arr[i]);

            if(count) ans++;
        }
        st.insert(arr[i]);
    }

    cout<<ans<<endl;



}

 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(25);
    int t = 1;
    // //cin >> t;
    while (t--)
    {
        solve();
    }
}

