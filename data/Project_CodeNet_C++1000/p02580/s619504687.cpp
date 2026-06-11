#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <limits>
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int_INF 2147483647
#define pint_INF 2000000000
#define ll_INF 	9223372036854775807
#define MOD 1000000007
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vvc vector<vector<char>>
#define vll vector<long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define sysp system("PAUSE")
#define pno cout << "no" << endl
#define pyes cout << "yes" << endl
#define pYes cout << "Yes" << endl
#define pNo cout << "No" << endl
#define pNO cout << "NO" << endl
#define pYES cout << "YES" << endl
#define endl "\n"
#define pi 3.14159265358979
using namespace std;
using ll = long long;
#define int ll

signed main(){
    int H,W,M;
    cin >> H >> W >> M;
    vvi bombs(M);
    vi row_wise(H);
    vi column_wise(W);
    rep(i,M){
        int h,w; cin >> h >> w;
        --h; --w;
        row_wise[h]++;
        column_wise[w]++;
        bombs[i] = {h,w};
    }
    int rowmax = *max_element(ALL(row_wise));
    int rowmax_cnt = 0;
    int colmax = *max_element(ALL(column_wise));
    int colmax_cnt=  0;
    set<int> row_wise_boolean;
    set<int> column_wise_boolean;
    for(int i = 0; i < H; i++){
        if(row_wise[i] == rowmax){
            row_wise_boolean.insert(i);
            rowmax_cnt++;
        }
    }

    for(int j = 0; j < W; j++){
        if(column_wise[j] == colmax){
            column_wise_boolean.insert(j);
            colmax_cnt++;
        }
    }

    int max_total = rowmax_cnt * colmax_cnt;
    int Nbombs_in_premises = 0;
    for(auto coor : bombs){
        bool row_flag = row_wise_boolean.find(coor[0]) != row_wise_boolean.end();
        bool col_flag = column_wise_boolean.find(coor[1]) != column_wise_boolean.end();
        if(row_flag && col_flag){
            Nbombs_in_premises++;
        }
    }

    int ans = rowmax + colmax;
    if(Nbombs_in_premises == max_total){
        ans--;
    }

    cout << ans << endl;
    sysp;
}