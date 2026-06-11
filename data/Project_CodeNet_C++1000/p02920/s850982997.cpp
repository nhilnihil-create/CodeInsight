#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    set<pair<int,int>,greater<pair<int,int>>> ss;
    for(int i=0;i<(1<<n);++i){
        int s;
        cin >> s;
        ss.emplace(s, i);
    }
    vector<int> gen;
    gen.push_back(ss.begin()->first);
    ss.erase(ss.begin());
    for(int i=0;i<n;++i){
        for(int j=0;j<(1<<i);++j){
            int p = gen[j];
            auto c = ss.upper_bound({p,0});
            if(c==ss.end()){
                cout << "No" << endl;
                return 0;
            }
            gen.push_back(c->first);
            ss.erase(c);
        }
    }
    cout << "Yes" << endl;

    return 0;
}