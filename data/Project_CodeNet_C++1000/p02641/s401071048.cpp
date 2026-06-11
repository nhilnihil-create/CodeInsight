#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
    int x, n;
    vector<int> p;

    cin >> x >> n;
    rep (i, n) {
        int tmp;
        cin >> tmp;
        p.push_back(tmp);
    }

    if(find(p.begin(), p.end(), x) == p.end()) {
        cout << x << endl;
    } else {
        int left=x, right=x;
        while( find(p.begin(), p.end(), left) != p.end()){
            left--;
        }
        while( find(p.begin(), p.end(), right) != p.end()){
            right++;
        }

        cout << (abs(x - left) <= abs(x - right) ? left : right )<< endl;
    }
    

    return 0;
}
