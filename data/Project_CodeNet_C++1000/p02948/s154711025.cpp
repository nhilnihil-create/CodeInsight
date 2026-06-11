#include <algorithm>
#include <iostream>
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
using P = pair<int, int>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define INF 100000000000
#define MAX 200001
#define MOD 1000000007
ll fac[MAX], finv[MAX], inv[MAX];
const int MX = 1000005;

int main(){
    int N, M; 
    cin >> N >> M;
    vector<P> AB(N);
    priority_queue<int> que;
    for(int i = 0; i < N; i++){
        int a, b; 
        cin >> a >> b;
        AB[i] = {a, b};
    }
    sort(AB.begin(), AB.end());
    int idx = 0;
    int day = 1;
    int ans = 0;
    while(day != M + 1){
        int cnt = 0;
        for(int i = idx; i < N; i++){
            if(AB[i].first <= day){
                cnt++;
                que.push(AB[i].second);
            }
            else break;
        }
        idx += cnt;
        day++;
        if(!que.empty()){
            ans += que.top();
            que.pop();
        }
    }
    cout << ans << endl;
}