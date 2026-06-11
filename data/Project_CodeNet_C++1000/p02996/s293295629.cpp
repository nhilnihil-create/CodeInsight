#include <bits/stdc++.h>
using namespace std;
int INF = 1e9+7;
typedef pair<int,int> P;
int main() {
    int N;
    cin >> N;
    vector<P>AB(N);
    for(int i = 0; i < N; i++) {
        int A,B;
        cin >> A >> B;
        AB[i].first = B;
        AB[i].second = A;
    }
    sort(AB.begin(),AB.end());
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        cnt+=AB[i].second;
        if(cnt > AB[i].first) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}