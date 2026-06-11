#include<bits/stdc++.h>
using namespace std;
#define int long long
//A[i]+A[j] == i-j;
//j+A[i] == i-A[j]
signed main(){
    int N;
    cin >> N;
    vector<int>A(N);
    map<int,int>Map;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        Map[i+1-A[i]]++;
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        ans+=Map[A[i]+i+1];
    }
    cout << ans << endl;
}
//4 0 1 -2 3 2
//6 4 7 6 13 14