#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define INF 1e9
#define MAXN 100005
#define MAXM 100005
#define MOD 1000000007
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define pii pair<int, int>

ll ans;
int N, K, S, cur, num;

void solve(){
    rep(i, N){
        if(i < K)
            cout << S;
        else{
            if(S + 1  <= INF)
                cout << S+1;
            else
                cout << 1;
        }
 
        if(i == N-1) cout << endl;
        else cout << " ";
    }
}

int main(){
    cin >> N >> K >> S;

    solve();
}
