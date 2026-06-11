#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i=0; i<S.size(); i++) cin >> S.at(i);

    sort(S.begin(), S.end());

    int ans = N;

    for (int i=1; i<S.size(); i++){
        if (S.at(i) == S.at(i-1))
            ans -= 1;
    }
    cout << ans << endl;
}