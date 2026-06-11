#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    string S;
    cin >> S;

    vector<int> ans;
    int i = n;
    while (i > 0){
        int j = max(0, i - m);
        for (; j < i; j++){
            if (S[j] == '0'){
                break;
            }
        }
        if (i == j){
            puts("-1");
            return 0;
        }

        ans.push_back(i - j);
        i = j;
    }

    copy(ans.rbegin(), ans.rend(), ostream_iterator<int>(cout, " "));
    cout << endl;
}
