#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> S(1 << N);
    for(int i = 0; i < 1 << N; ++i) cin >> S[i];
    sort(S.rbegin(), S.rend());
    
    int prev_val = S[0];
    S[0] = 0;
    multiset<int> st;
    for(int i = 1; i < 1 << N; ++i){
        if(S[i] == prev_val)    S[i] = S[i - 1];
        else{
            prev_val = S[i];
            S[i] = S[i - 1] + 1;
        }
        st.insert(S[i]);
    }
    
    vector<int> vs(1, 0);
    for(int k = 0; k < N; ++k){
        vector<int> que;
        for(int v : vs){
            auto it = st.upper_bound(v);
            if(it == st.end()){
                cout << "No\n";
                return 0;
            }
            que.push_back(*it);
            st.erase(it);
        }
        for(int v : que)    vs.emplace_back(v);
    }
    cout << "Yes\n";
}