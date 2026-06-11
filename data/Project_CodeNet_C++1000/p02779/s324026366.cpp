#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i )

using namespace std;
typedef long long ll;

int main(){
    int N; cin >> N;
    set<int> num_set;
    vector<int> vec_set;

    rep(i,N){
        int tmp; cin >> tmp;
        num_set.insert(tmp);
        vec_set.push_back(tmp);
    }

    if (num_set.size() == vec_set.size()){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}