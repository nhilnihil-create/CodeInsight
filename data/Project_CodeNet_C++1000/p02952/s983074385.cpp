#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,count = 0;
    cin >> n;
    for (int i = 1; i < n+1; i++){
        string s = to_string(i);
        if(!(s.size() % 2 == 0))count++;
    }
    cout << count << endl;
}