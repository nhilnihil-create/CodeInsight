#include<bits/stdc++.h>
using namespace std;

int N;
int A[300010];
vector<int> V;
int ans[300010];

int main() {

    cin >> N;
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A[a]++;
    }

    for(int i = 1; i <= N; i++) {
        V.push_back(A[i]);
    }
    sort(V.begin(), V.end());

    int tmp = N;
    int sum = 0;
    int idx = 0;
    for(int i = 0; i < N; i++) {
        while(V.size() != idx && V[idx] == i) {
            idx++;
            tmp--;
        }

        sum += tmp;

        ans[sum / (i + 1)] = i + 1;
    }

    int MAX = 0;
    for(int i = N; i > 0; i--) {
        MAX = max(MAX, ans[i]);
        ans[i] = MAX;
    }

    for(int i = 1; i <= N; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
