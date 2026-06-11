#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
using namespace std;
typedef vector<int> vi;
#define int long long

signed main(){
    int N;
    cin >> N;
    vector<int> d(N);
    rep(i, N) cin >> d[i];

    sort(d.begin(), d.end());
    cout << d[(N-1) / 2 + 1] - d[(N-1) / 2] << endl;

    //int counter = 0;
    /*rep(i, d[N-1]){
        if(i > d[(N-1) / 2] && i <= d[(N-1) / 2 + 1]){
            counter++;
        }
    }*/

    //cout << counter << endl;
    return 0;
}