#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    multiset<int> st;
    for(int i=0; i<(1<<N); i++){
        int a;
        cin >> a;
        st.insert(-a);
    }
    vector<int> now = {*st.begin()};
    st.erase(st.begin());
    for(int i=1; i<=N; i++){
        vector<int> born;
        for(int a : now){
            auto it = st.upper_bound(a);
            if(it == st.end()){
                cout << "No" << endl;
                return 0;
            }
            born.push_back(*it);
            st.erase(it);
        }
        for(int a : born) now.push_back(a);
    }
    cout << "Yes" << endl;
    return 0;
}
