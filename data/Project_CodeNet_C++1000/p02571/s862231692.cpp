#include <iostream>
using namespace std;

int main() {
    string s,x;
    cin >> s >> x;
    int n = s.size();
    int m = x.size();
    int mx = 1001;
    for (int i = 0; i < n - m + 1; i++){
        string temp;
        int cnt = 0;
        for (int j = i; j < i + m; j++){
            temp += s[j];
        }
        for (int j = 0; j < m; j++){
            if (temp[j] == x[j])
                cnt++;
        }
        mx = min(mx,m - cnt);
    }
    cout << mx << endl;
    return 0;
}

//