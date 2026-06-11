#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    string S;
    cin >> S;
    int len = S.size();
    int ans = 0;
    if (len == 1){
        ans = 1;
    }
    else if (len == 2){
        if (S[0] == S[1]) ans = 1;
        else ans = 2;
    }
    else{
        int count = 0;
        while(true){
            if (S.size() == 1){
                count++;
                break;
            }
            else if (S.size() == 2){
                if (S[0] == S[1]) count++;
                else count += 2;
                break;
            }
            else if (S.size() == 3){
                if (S[1] == S[2]) count += 2;
                else if (S[0] == S[1]) count += 2;
                else count += 3;
                break;
            }
            else{
                if (S[S.size() - 1] == S[S.size() - 2]){
                    S = S.substr(0, S.size() - 3);
                    count += 2;
                }
                else{
                    S = S.substr(0, S.size() - 1);
                    count++;
                }
            }
        }
        ans = count;
    }
    cout << ans << endl;
}
