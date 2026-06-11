#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    string S,T;
    cin >> S >>T;
    vector<set<int>> salpha(26);
    for(int i=0;i<S.size();i++){
        int t = S[i] -'a';
        salpha[t].insert(i);
    }
    ll N = S.size();
    ll ans =0;
    ll cursor =0;
    for(int i=0;i<T.size();i++){
        int t = T[i]-'a';
        if(salpha[t].size()==0){
            cout<< -1 << endl;
            return 0;
        }
        auto itr = salpha[t].lower_bound(cursor);
        if(itr == salpha[t].end()){
            ans += (N-cursor);
            cursor = 0;
            itr = salpha[t].lower_bound(cursor);
        }
        ans += (*itr)-cursor+1;
        cursor = (*itr) +1;        
    }
    cout << ans << endl;

    return 0;
}