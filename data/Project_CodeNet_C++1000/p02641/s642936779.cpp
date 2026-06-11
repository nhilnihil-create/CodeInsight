#include <bits/stdc++.h>
using namespace std;

int main(){
    int X, N, near=0, dif, count=0, ans1, ans2, ans=0;
    cin >> X >> N;

    if(N == 0){
        cout << X << endl;
        return 0;
    }

    vector<int> P(N);

    for(int n=0; n<N; n++){
        cin >> P.at(n);
    }

    for(int i=0; i<N; i++){
        count = 0;
        for(int n=0; n<N && count != 2; n++){
            dif = X - P.at(n);
            if(abs(dif) == near){
                ans1 = dif;
                count++;
            } else if(abs(dif) == near && count == 1) {
                count++;
            }
        }
        if(count == 0){
            ans = X - near;
            break;
        } else if(count == 1 && ans1 != 0){
            ans = X + ans1;
            break;
        }
        near++;
    }
    cout << ans << endl;
    return 0;
}