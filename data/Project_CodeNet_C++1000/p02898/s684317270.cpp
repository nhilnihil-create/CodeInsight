#include<iostream>
#include<bitset>
#include<vector>
#include<map>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;

int main() {
    int n, k;
    vector<int> h;
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        int s;
        cin >> s;
        h.push_back(s);
    }

    int cnt=0;

    for(int i = 0; i < n; i++){
        if(h[i] >= k) cnt++;
    }

    cout << cnt << endl;
}