#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double PI=acos(-1);
const int INF = numeric_limits<int>::max();

int main(){
    string s;
    cin >> s;

    rep(i, s.size()){
        if(i % 2 == 0){
            if(s[i] != 'R' && s[i] != 'U' && s[i] != 'D'){
                cout<<"No"<<endl;
                return 0;
            }
        }
        if(i % 2 != 0){
            if(s[i] != 'L' && s[i] != 'U' && s[i] != 'D') {
                cout<<"No"<<endl;
                return 0;
            }
        }
    }


    cout<<"Yes"<<endl;

    //cout << fixed << setprecision(6) << ans << endl;

    return 0;
    
}