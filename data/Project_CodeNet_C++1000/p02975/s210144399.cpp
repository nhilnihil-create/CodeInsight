#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 , -1};
signed main(){
    int N;
    cin >> N;
    vector<int>a(N);
    map<int,int>Mp;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        Mp[a[i]]++;
    }
    if(Mp.size() == 1) {
        if(Mp[0] == N) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    else if(Mp.size() == 2) {
        // 550550550
        if(N%3 == 0 && Mp[0] == N/3) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    else if(Mp.size() == 3) {
        int ok = 0;
        for(P p:Mp) {
            ok^=p.first;
            if(p.second != N/3) {
                cout << "No" << endl;
                return 0;
            }
        }
        if(ok == 0) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    else {
        cout << "No" << endl;
    }
}
