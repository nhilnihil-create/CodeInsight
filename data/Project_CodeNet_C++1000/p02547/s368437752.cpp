
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
using namespace std;
typedef long long ll;




int main() {
    int n;
    cin >> n;
    int cnt = 0;
    bool can = false;

    for (int i = 0; i < n;i++){
        int a, b;
        cin >> a >> b;
        if(a == b)
            cnt++;
        else
            cnt = 0;

        if(cnt==3)
            can = true;
    }
    cout << (can ? "Yes" : "No");
    return 0;
}