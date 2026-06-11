#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin >> n; 
    vector<int> w(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> w[i];
        sum += w[i];
    }
    int mn = INT_MAX, s1 = 0;
    for(int i = 0; i < n; i++){
        s1 += w[i];
        mn = min(mn, abs(s1 * 2 - sum));
    }
    cout << mn << endl;
    return 0;
}