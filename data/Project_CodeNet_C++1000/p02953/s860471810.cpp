#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    int k;
    cin >> k;
    k--;
    rep(i,n-1){
        int h;
        cin >> h;
        if(k > h){
            cout << "No" << endl;
            return 0;
        }
        else k = max(k, h-1);
    }
    cout << "Yes" << endl;
}