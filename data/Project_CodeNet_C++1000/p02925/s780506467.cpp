#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

int A[1010][1010];
int process[1010];
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    
    rep(i, N) {
        rep(j, N - 1) {
            cin >> A[i][j];
            A[i][j]--;
        }
    }
    int ans = 0;
    int cnt = 0;
    set<int> st;
    rep(i, N) st.insert(i);
    while(true) {
        bool change = false;
        bool used[1010] = {};
        vector<int> v;
        for(auto itr = st.begin(); itr != st.end(); itr++) {
            int j = *itr;
            int p = A[j][process[j]];
            if(!used[j] && !used[p] && A[p][process[p]] == j) {
                //cerr << ans << " " << j << " " << p << endl;
                used[j] = true;
                used[p] = true;
                process[p]++;
                process[j]++; 
                if(process[p] < N - 1) v.push_back(p);
                if(process[j] < N - 1) v.push_back(j);
                cnt++;
                change = true;
            }
        }
        st.clear();
        for(auto e: v) st.insert(e);
        if(!change) break;
        ans++;
    }
    if(cnt != N * (N - 1) / 2) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }


    return 0;
}
