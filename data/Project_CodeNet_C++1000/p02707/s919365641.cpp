#include <bits/stdc++.h>
#include <string>
using namespace std;


int main(){
    int64_t n;

    cin >> n;
    vector<int> vec(n-1);
    vector<int> ans(n, 0);

    for (int i = 0; i < n - 1; i++) cin >> vec.at(i);
    for (int i = 0; i < n - 1 ; i++) ans.at(vec.at(i)-1)++;
    for (int i = 0; i < n; i++) cout << ans.at(i) << endl;

}