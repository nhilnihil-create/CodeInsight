#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, ans = 0;
    cin >> N;
    vector<int> P(N+1);
    for(int i = 1; i <= N; ++i) cin >> P[i];
    int buf = 2*pow(10,6);
    for(int i = 1; i <= N; ++i){
        if(buf >= P[i]){
            buf = P[i];
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}