#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    long long ans = 0;
    for(int i = 1; i < N; i++){
        long long cnt = 0;
        for(int j = 0; j + i < N; j++){
            if(S[j] == S[i + j]) cnt++;
            else cnt = 0;
            if(cnt > i) ans = max(ans, (long long)i);
            else ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
}