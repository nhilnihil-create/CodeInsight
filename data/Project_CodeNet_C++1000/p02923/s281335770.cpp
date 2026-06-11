#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 1; i < n; i++)
typedef long long ll;
typedef pair<int, int> pii;


int main() {
    int n; cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec.at(i);
    }
    int max = vec.at(0);
    vector<int> c_vec;
    int count = 0;
    rep(i, n){
        int min = vec.at(i);
        if(max >= min) {
            count++;
            max = min;
        }else{
            c_vec.push_back(count);
            count=0;
            max = min;
        }
    }
    c_vec.push_back(count);
    std::sort(c_vec.begin(), c_vec.end(), std::greater<int>());
    cout << c_vec.at(0) << endl;
    return 0;
}
