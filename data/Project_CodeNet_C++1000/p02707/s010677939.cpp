#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> cnt(n);
    for(int i = 1; i < n; i++){
        int a;
        cin >> a;
        cnt[a-1]++;
    }
    for(auto c : cnt){
        cout << c << endl;
    }
    return 0;
}