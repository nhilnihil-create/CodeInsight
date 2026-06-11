#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
int main(){
    string s, t;
    cin >> s >> t;
    vector<set<int>> alp(26);
    for(int i = 0; i < (int)s.size(); i++){
        alp[s[i] - 'a'].insert(i);
    }
    int pre = 0;
    long long ans = 0;
    long long cnt = 1;
    for(int i = 0; i < (int)t.size(); i++){
        int ind = t[i] - 'a';
        if(alp[ind].empty()){
            cout << -1 << endl;
            return 0;
        }
        if(i == 0){
            auto ite = alp[ind].begin();
            ans += (long long)*ite;
            pre = *ite;
        }
        else{
            int flag = 0;
            if(t[i] == t[i - 1]) {
                pre++;
                flag++;
            }
            auto ite = alp[ind].lower_bound(pre);
            if(ite == alp[ind].end()){
                ans = cnt * (long long)s.size() + (long long)*alp[ind].begin();
                pre = *alp[ind].begin();
                cnt++;
            }
            else{
                if(flag == 0) ans += (long long)(*ite - pre);
                else ans += (long long)(*ite - pre) + 1;
                pre = *ite;
            }
        }
    }
    cout << ans + 1 << endl;
}