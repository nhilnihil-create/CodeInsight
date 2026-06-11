#include <bits/stdc++.h>
#include <string>
using namespace std;


int main(){
    int64_t n, a = 1, ans = 1;

    cin >> n;
    vector<string> vec(n);


    for (int i = 0; i < n; i++) cin >> vec.at(i);

    sort( vec.begin(), vec.end());

    for (int i = 1; i < n; i++) {
        if(vec.at(i -1) != vec.at(i)) ans++;
    }
    cout << ans << endl;
}