#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string s,t;
    cin >> s;
    cin >> t;

    long long n = s.size();
    long long m = t.size();

    vector<vector<long long> > index(30);

    for(long long i = 0; i < n; i++) index[s[i]-'a'].push_back(i+1);

    long long ans = 0;
    long long last = 0;

    for(long long i = 0; i < m; i++){
        long long nch = t[i] - 'a';
        if(index[nch].size() <= 0){
            printf("-1\n");
            return 0;
        }

        auto itr = upper_bound(index[nch].begin(), index[nch].end(), last);

        if(itr == index[nch].end()){
            ans += n;
            itr = index[nch].begin();
        }
        last = *itr;
    }
    ans += last;
    cout << ans << endl;
    return 0;
}