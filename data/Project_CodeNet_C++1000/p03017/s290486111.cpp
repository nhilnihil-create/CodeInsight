#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define INF 1e9
#define MAXN 100005
#define MAXM 100005
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define pii pair<int, int>

ll ans;
int A,B,C, D, N;
string S;
bool flag = true;

void solve(){
    rep(i, N-1){
        if(S.substr(i,2) =="##"){
            if( (A <= i && i+1 <= C) || ( B <= i && i+1 <= D)){
                flag = false;
                break;
            }
        }
    }

    if(flag && D < C){
        flag = false;

        rep(i, N-2){
            if(S.substr(i,3) == "..." &&  B <= i+1 && i+1 <= D) flag = true;
        }
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main(){
    cin >> N >> A >> B >> C >> D >> S;

    A--, B--, C--, D--;

    solve();
}
