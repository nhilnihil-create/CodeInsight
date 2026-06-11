#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(void){

    string s, t;
    cin >> s >> t;

    int sum = 0, ans=t.size();
    for(int i=0; i<s.size()-t.size()+1; i++){
        for(int j=0; j<t.size(); j++){
            if(s.at(i+j) != t.at(j)) sum++;
        }
        if(ans > sum) ans=sum;
        sum=0;
    }
    cout << ans << endl;

    return 0;
}