#include <bits/stdc++.h>
using namespace std;
//Robot Arms

typedef pair<int ,int> P;

int main(){
    int N;
    cin >> N;
    vector<int> x(N);
    vector<int> l(N);
    vector<P> t(N);

    for(int i = 0; i < N; ++i){
        cin >> x[i] >> l[i];
        t[i].first = x[i] + l[i];
        t[i].second = x[i] - l[i];
    }

    sort(t.begin(), t.end());

    int ans = 0;
    int nt = -1e9;

    for(int i = 0; i < N; ++i){
        if(t[i].second >= nt){
            ans++;
            nt = t[i].first;
        }
    }

    cout << ans << endl;
    return 0;
}