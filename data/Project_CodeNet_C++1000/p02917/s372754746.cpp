#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N;
    cin >> N;
    int B[N-1];
    for(int i=0; i<N-1; i++){
        cin >> B[i];
    }
    int ans = B[0];
    for(int i=1; i<N-1; i++){
        ans += min({B[i],B[i-1]});
    }
    ans += B[N-2];

    cout << ans << endl;
    return 0;
}