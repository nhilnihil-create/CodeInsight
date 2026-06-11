#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};
signed main() {
    int N;
    cin >> N;
    vector<pair<double,double>>AB(N);
    for(int i = 0; i < N; i++) {
        cin >> AB[i].first >> AB[i].second;
    }
    sort(AB.begin(),AB.end());
    int X = 0,Y = 0;
    if(N%2 == 0) {
        X = AB[N/2-1].first+AB[N/2].first;
    }
    else {
        X = AB[N/2].first;
    }
    for(int i = 0; i < N; i++) {
        swap(AB[i].first,AB[i].second);
    }
    sort(AB.begin(),AB.end());
    if(N%2 == 0) {
        Y = AB[N/2-1].first+AB[N/2].first;
    }
    else {
        Y = AB[N/2].first;
    }
    cout << Y-X+1 << endl;
}
