#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i,n) for(int i=0; i < (int)(n); i++)

int main(){
    int N;
    cin >> N;

    string S;
    cin >> S;

    int ans = 0;
    rep(pass,1000){
        vector<int> password(3);
        password.at(0) = pass/100;
        password.at(1) = pass/10 - pass/100 * 10;
        password.at(2) = pass%10;
        bool a1,a2,a3;
        a1 = a2 = a3 = false;
        rep(i,N){
            if(!a1 && S.at(i) == ('0' + password.at(0))){
                a1 = true;
                continue;
            }
            if(!a2 && a1 && S.at(i) == ('0' + password.at(1))){
                a2 = true;
                continue;
            } 
            if(a2 && S.at(i) == ('0' + password.at(2))){
                a3 = true;
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
