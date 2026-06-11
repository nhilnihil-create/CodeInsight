
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++){
        if(i%2==0){ //奇数文字目
            if(s[i]!='R' && s[i]!='U' && s[i]!='D'){
                cout << "No" << endl;
                return 0;
            }
        }
        if(i%2==1){
            if(s[i]!='L' && s[i]!='U' && s[i]!='D'){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}