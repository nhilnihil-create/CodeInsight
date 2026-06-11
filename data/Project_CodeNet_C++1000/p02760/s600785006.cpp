#include <bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define int long long
#define ld long double
#define fi first
#define se second
#define all(uiet) uiet.begin(),uiet.end()
#define read(UIET) for(int i = 0; i < n; ++i) cin >> UIET[i]
#define out(UIET) for(int i = 0; i < n; ++i) cout << UIET[i]
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define vpp vector<pair< int, int > >
#define pll pair<int , int >
#define ppll pair < pll , pll >
#define debug(n1) cout << n1 << endl
#define len(a) ((int) (a).size())
#define endl "\n"
#define mod 1000000007
const int INF=(1LL<<60)-1;
int32_t main(){
    SPEED;
    int arr[3][3];
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            cin >> arr[i][j];
        }
    }
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        int check = 0;
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                if(arr[i][j] == x) {
                    arr[i][j] = 0;
                    check = 1;
                    break;
                }
            }
            if(check) break;
        }
    }
    for(int i = 0; i < 3; ++i){
        if(arr[i][0] == 0 && arr[i][1] == 0 && arr[i][2] == 0){
            cout << "Yes" << endl;
            return 0;
        }
        if(arr[0][i] == 0 && arr[1][i] == 0 && arr[2][i] == 0){
            cout << "Yes" << endl;
            return 0;
        }
    }
    if(arr[0][0] == 0 && arr[1][1] == 0 && arr[2][2] == 0){
        cout << "Yes" << endl;
        return 0;
    }
    if(arr[2][0] == 0 && arr[1][1] == 0 && arr[0][2] == 0){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}
