#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll ZERO = 0;
const int Inf = 1000000000;
const ll INF= 1e18;
const ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i);
    }
    sort(vec.begin(),vec.end());
    vector<bool> cnt(N);
    if(vec.at(0) >= 0){
        for(int i = 1;i < N;i++) {
            cnt.at(i) = true;
        }
    }
    else if(vec.at(N - 1) <= 0) {
        cnt.at(N - 1) = true;
    }
    else {
        for(int i = 1;i < N;i++) {
            if(vec.at(i) >= 0) {
                cnt.at(i) = true;
            }
        }
    }
    int ret = 0;
    for(int i = 0;i < N;i++) {
        if(cnt.at(i) == true) {
            ret += vec.at(i);
        }
        else {
            ret -= vec.at(i);
        }        
    }
    cout << ret << endl;
    ret = vec.at(0);
    for(int i = N - 1;i >= 0;i--) {
        if(cnt.at(i - 1) == false) {
            cout << vec.at(i) << " " << ret << endl;
            ret = vec.at(i) - ret;
            break;
        }
        else {
            cout << ret << " " << vec.at(i) << endl;
            ret -= vec.at(i);
        }
    }
    for(int i = 1;i < N;i++) {
        if(cnt.at(i) == true) {
            break;
        }
        else {
            cout << ret << " " << vec.at(i) << endl;
            ret -= vec.at(i);
        }
    }
}