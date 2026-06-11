#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> ans(n);
    int k, j;
    for(int i = 0; i < n; i = k){
        int x, y;
        j = i + 1;
        while(j < n && s[j] == 'R')
            j++;
        k = j + 1;
        while(k < n && s[k] == 'L')
            k++;
        x = j - i;
        y = k - j;
        ans[j - 1] = (x + 1) / 2 + y / 2;
        ans[j] = x / 2 + (y + 1) / 2;
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}