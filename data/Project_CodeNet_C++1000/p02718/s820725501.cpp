#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, l, r) for (ll i = (ll)l; i < (ll)(r); i++)
#define INF 1000000000000000000
#define MAX 200001
#define MOD 1000000007

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};

int main(){
    int N, M;
    int sum = 0;
    cin >> N >> M;
    vector<int> A(N);
    rep(i,N){
        cin >> A[i];
        sum += A[i];
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    int flag = 1;
    if(A[M-1] * 4 * M < sum) flag = 0;
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}
