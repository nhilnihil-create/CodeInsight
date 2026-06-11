#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

const int ALP_NUM = 30;
vector<int> alp[ALP_NUM];

int main(){
    string s, t;
    cin >> s >> t;

    for(int i = 0; i < s.length(); i++){
        alp[s[i] - 'a'].push_back(i);
    }

    int count = 0;
    int now = -1;
    for(int i = 0; i < t.length(); i++){
        int t_num = t[i] - 'a';
        auto it = lower_bound(alp[t_num].begin(), alp[t_num].end(), 0);
        if (it == alp[t_num].end()){
            cout << -1 << endl;
            return 0;
        }
        auto it2 = upper_bound(alp[t_num].begin(), alp[t_num].end(), now);
        if (it2 == alp[t_num].end()){
            count++;
            now = *it;
        }
        else now = *it2;
    }
    long long int ans = (long long int)s.length() * count + now + 1;
    cout << ans << endl;
    return 0;
}