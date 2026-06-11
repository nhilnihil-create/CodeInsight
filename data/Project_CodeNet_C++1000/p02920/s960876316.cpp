#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool check(int N){
    multiset<int> S;
    for(int i=0;i<(1<<N);i++){
        int s; cin >> s;
        S.insert(s);
    }
    vector<int> v;
    {
        auto it = S.end();
        --it;
        v.push_back(*it);
        S.erase(it);
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<(1<<i);j++){
            auto it = S.lower_bound(v[j]);
            if(it == S.begin()) return false;
            --it;
            v.push_back(*it);
            S.erase(it);
        }
    }
    return true;
}

int main(){
    int N;
    while(cin >> N){
        cout << (check(N) ? "Yes" : "No") << endl;
    }
}