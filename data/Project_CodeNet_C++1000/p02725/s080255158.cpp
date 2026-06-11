#include <bits/stdc++.h>
#include <string>
using namespace std;


int main(){
    int n, k, ans, dis;

    cin >> k >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec.at(i);
    dis = k - vec.at(n-1) + vec.at(0);
    for (int i = 1; i < n; i++) dis = max(dis, vec.at(i) - vec.at(i-1));

    cout << k -dis << endl;

}