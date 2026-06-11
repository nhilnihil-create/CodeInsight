#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> A(N);
    vector<long long> B(N);
    vector<pair<long long, long long>> dis;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            long long disA, disB;
            if ((A[i] >= A[j] && B[i] >= B[j]) || (A[i] <= A[j] && B[i] <= B[j])) {
                disA = max(A[i], A[j]) - min(A[i], A[j]);
                disB = max(B[i], B[j]) - min(B[i], B[j]);
            } else {
                if (A[i] > A[j]) {
                    disA = A[j] - A[i];
                    disB = B[j] - B[i];
                } else {
                    disA = A[i] - A[j];
                    disB = B[i] - B[j];
                }
            }
            dis.push_back(make_pair(disA, disB));
        }
    }
    
    sort(dis.begin(), dis.end());
    dis.push_back(make_pair(0, 0));
    
    pair<long long, long long> now = dis[0];
    long long cnt = 1;
    long long mx = 0;
    for (int i = 1; i < dis.size(); i++) {
        if (now == dis[i]) {
            cnt++;
        } else {
            now = dis[i];
            mx = max(mx, cnt);
            cnt = 1;
        }
    }
    
    long long ans = N;
    ans -= mx;
    cout << ans << endl;
    return 0;
}