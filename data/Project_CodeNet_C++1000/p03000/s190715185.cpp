#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,x,basyo=0,count = 1;
    cin >> n >> x;
    vector<int> data(n);
    for (int i = 0; i < n; i++){
        cin >> data.at(i);
        basyo += data.at(i);
        if(basyo <= x)count ++;
    }
    cout << count << endl;
}