#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> job(N);
    rep(i, N){
        int A, B;
        cin >> A >> B;
        job[i] = make_pair(B, A);
    }
    sort(job.begin(), job.end());
    int tim = 0;
    for(auto aaa: job){
        tim+=aaa.second;
        if(tim>aaa.first){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
