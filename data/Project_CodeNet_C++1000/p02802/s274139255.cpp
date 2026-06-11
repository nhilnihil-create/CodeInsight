#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int n,m;
    cin >> n;
    set<int> st;
    cin >> m;
    map<int,int> mp;
    for(int i = 0; i < m; i++){
        int p;
        cin >> p;
        string s;
        cin >> s;
        if(s == "AC") st.insert(p);
        else {
            auto itr = st.find(p);
            if(itr == st.end()) mp[p]++;
        }
    }
    int pena = 0;
    for(auto p:st){
        pena += mp[p];
    }
    cout << st.size() << " " << pena << endl;
    return 0;
}