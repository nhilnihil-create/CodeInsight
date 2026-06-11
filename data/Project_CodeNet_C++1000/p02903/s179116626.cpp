#include <bits/stdc++.h>
#define ll long long
#define li long int
#define ld long double
#define pl pair<long long, long long>
#define pi pair<int, int>
#define ppl pair<pl, ll>
#define ppi pair<int, pi>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define LLFOR(i,a,b) for(ll i=a;i<b;i++)
#define fi first
#define se second
#define MOD 1000000007
#define M2 998244353
//std::cout <<setprecision(30) << av << endl;
using namespace std;

char grid[1000][1000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    FOR(i, 0, b){
        FOR(j, 0, a){
            grid[i][j]='0';
        }
    }
    FOR(i, 0, b){
        FOR(j, a, w){
            grid[i][j]='1';
        }
    }
    FOR(i, b, h){
        FOR(j, 0, a){
            grid[i][j]='1';
        }
    }
    FOR(i, b, h){
        FOR(j, a, w){
            grid[i][j]='0';
        }
    }
    FOR(i, 0, h){
        FOR(j, 0, w){
            cout << grid[i][j];
        }
        cout << "\n";
    }

}
