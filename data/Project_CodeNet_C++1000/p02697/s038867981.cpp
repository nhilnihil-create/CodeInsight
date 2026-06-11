#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N, M; cin >> N >> M;
    int mid = N / 2;
    if(N%2 == 1){
        int l = 1, r = mid;
        int cnt = 0;
        while(cnt < M && l < r){
            cout << l << " " << r << endl;
            l++; r--;
            cnt++;
        }
        l = mid+1;
        r = N;
        while(cnt < M && l < r){
            cout << l << " " << r << endl;
            l++; r--;
            cnt++;
        }
    } else {
        int l = 1, r = mid;
        int cnt = 0;
        while(cnt < M && l < r){
            cout << l << " " << r << endl;
            l++; r--;
            cnt++;
        }
        l = mid+1;
        r = N-1;
        while(cnt < M && l < r){
            cout << l << " " << r << endl;
            l++; r--;
            cnt++;
        }
    }

    return 0;
}