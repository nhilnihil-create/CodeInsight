#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n;
    string s;
    cin >> n >> s;
    if(n%2 == 1){
        cout << "No" << endl;
        return 0;
    }
    for(int i = 0; i < n/2;i++){
        if(s.at(i) != s.at(n/2 + i)){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}