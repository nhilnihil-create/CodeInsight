#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    int ans = 0;
    for(int i = 1; i <= N; i++){
        string str = to_string(i);
        if(str.size() % 2 == 1)
            ans++;
    }

    cout << ans << endl;

    return 0;
}