#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int ans = 0;
    for (int i=1; i<=N; i++){
        string S = to_string(i);
        if(S.size() % 2 == 1) ans += 1;
    }
    cout << ans << endl;
}