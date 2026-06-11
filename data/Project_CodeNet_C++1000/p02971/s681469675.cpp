#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    int n; cin >> n;
    vector<int> vec(n);
    rep(i,n) {
        cin >> vec.at(i);
    }
    vector<int> vec_2 = vec;
    sort(vec_2.begin(), vec_2.end(), std::greater<int>());
    rep(i, n){
        if(vec.at(i) != vec_2.at(0)) cout << vec_2.at(0) << endl;
        else{
            cout << vec_2.at(1) << endl;
        }
    }

    return 0;
}

