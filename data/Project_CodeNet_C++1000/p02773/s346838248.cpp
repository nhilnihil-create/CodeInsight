#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int n;
    string si;
    int maxvote=-1;
    cin >> n;
    // n = 2;
    vector<string> ss(n+1);
    for (int i=0; i<n; i++) {
        cin >> si;
        ss[i] = si;
    }
    // ss[0] = "xx";
    // ss[1] = "xx";
    ss[n] = "zzzzzzzzzzz";

    vector<string> ans(n);
    string cur = "";
    int curcnt = 0;
    // for (int i=0; i<n; i++) cout << ss[i];
    sort(ss.begin(), ss.end());
    // cout << endl;
    // for (int i=0; i<n; i++) cout << ss[i];

    for (int i=0; i<n; i++){
        if (ss[i] != cur) {
            curcnt = 1;
        } else {
            curcnt++;
        }
        cur =  ss[i];

        if (maxvote < curcnt) {
            maxvote = curcnt;
            ans.clear();
            ans.push_back(cur);
        } else if (maxvote == curcnt){
            ans.push_back(cur);
        }
    }
    // cout << endl << "answer from here" << endl;
    // cout << ans.size();
    for (int i=0; i<ans.size(); i++){
        cout << ans[i] << endl;
    }
    // cout << endl;
    // cout << ans;

}