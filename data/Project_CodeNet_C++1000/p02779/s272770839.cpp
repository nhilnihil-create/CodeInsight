#include <bits/stdc++.h>
using namespace std;

int main() {
    set<long long>s;
    int len;
    cin >> len;
    while(len--){
        long long ai;
        cin >> ai;
        if(s.find(ai) != s.end()){
            cout << "NO" << endl;
            return 0;
        }else{
            s.insert(ai);
        }
    }
    cout << "YES" << endl;
}