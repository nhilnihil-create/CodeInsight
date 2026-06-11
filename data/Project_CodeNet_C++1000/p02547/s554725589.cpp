#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define fio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define mod 1000000007
bool compare(int a, int b) {
    return a > b;
}
int main() {
    fio;
    int n;
    cin >> n;
    vector<int>v;
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        if (s == e) {
            v.push_back(1);
        }
        else {
            v.push_back(0);
        }
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
        //cout << v[i] << " ";
        if (v[i] == 1) {
            for (int j = i; j < i + 3; j++) {
                if (v[j] == 1) {
                    flag++;
                    continue;
                }
                else {
                    break;
                }
            }
            if (flag == 3) {
                cout << "Yes" << endl;
                return 0;
            }
            flag = 0;
        }
    }
    cout << "No" << endl;
    return 0;
}