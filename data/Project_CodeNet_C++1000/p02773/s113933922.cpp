#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstddef>
#include<queue>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; ++i) cin >> s.at(i);
    sort(s.begin(), s.end());
    vector<pair<int, string>> p;
    int cnt = 1;
    for(int i = 1; i < n; ++i){
        if(s.at(i) == s.at(i - 1) && i != n - 1) cnt++;
        else if(s.at(i) != s.at(i - 1) && i != n - 1){
            p.push_back(make_pair(cnt, s.at(i - 1)));
            cnt = 1;
        }
        else if(s.at(i) == s.at(i - 1) && i == n - 1){
            cnt++;
            p.push_back(make_pair(cnt, s.at(i)));
        }
        else if(s.at(i) != s.at(i - 1) && i == n - 1){
            p.push_back(make_pair(cnt, s.at(i - 1)));
            cnt = 1;
            p.push_back(make_pair(cnt, s.at(i)));
        }
    }
    if(p.size() == 1) cout << p.at(0).second << endl; 
    else{
        sort(p.rbegin(), p.rend());
        int mx = p.at(0).first, i = 0;
        vector<string> ans;
        while(i < p.size() && p.at(i).first == mx){
            ans.push_back(p.at(i).second);
            i++;
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); ++i) cout << ans.at(i) << endl;
    }
    return 0;
}