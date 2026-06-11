#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end() 
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000
using namespace std;
typedef long long ll;

int main() {
    int A[3][3];
    vector<vector<bool>> field(3, vector<bool>(3));
    int n;

    REP(i, 3){
        REP(j, 3){
            cin >> A[i][j];
        }
    }
    cin >> n;
    int b[n];
    map<int, int> mp;

    REP(i, n){
        cin >> b[i];
        mp[b[i]] = 1;
    }

    REP(i, 3){
        REP(j, 3){
            if(mp[A[i][j]] != 0){
                field[i][j] = true;
            }
        }
    }

    bool flag = false;
    if(field[0][0] == true && field[1][1] == true && field[2][2] == true){
        flag = true;
    }
    if(field[0][2] == true && field[1][1] == true && field[2][0] == true){
        flag = true;
    }

    REP(i, 3){
        if(field[i][0] == true && field[i][1] == true && field[i][2] == true){
            flag = true;
        }
        if(field[0][i] == true && field[1][i] == true && field[2][i] == true){
            flag = true;
        }
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}