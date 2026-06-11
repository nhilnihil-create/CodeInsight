#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s, t;
    cin >> s >> t;

    int sn = s.length();
    int tn = t.length();

    map<char, int> m;
    vector<vector<int> > v(26);
    for(int i = 0; i < sn; i++){
        auto itr = m.find(s[i]);
        if(itr == m.end()){
            m[s[i]] = 1;
        }
        v[s[i] - 'a'].push_back(i);
    }

    int flag = 0;
    for(int i = 0; i < tn; i++){
        auto itr = m.find(t[i]);
        if(itr == m.end()){
            flag = 1;
            break;
        }
    }

    if(flag == 0){
        int now = 0;
        ll cou = 0;
        int k = -1;
        while(1){
            if(now == tn){
                break;
            }

            auto itr = upper_bound(v[t[now] - 'a'].begin(), v[t[now] - 'a'].end(), k);
            if(itr == v[t[now] - 'a'].end()){
                k = v[t[now] - 'a'][0];
                cou++;
            }else{
                k = *itr;
            }
            now++;
        }

        cout << sn * cou + k + 1 << endl;
    }else{
        cout << -1 << endl;
    }
}