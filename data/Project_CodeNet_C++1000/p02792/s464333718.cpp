#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<vector<int>>> num(10, vector<vector<int>>(10));
    for(int i=1; i<=n; i++){
        int a = i;
        int bottom = a % 10;
        if(bottom == 0) continue;

        while(a >= 10){
            a /= 10;
        }
        int top = a;
        
        num[top][bottom].push_back(i);
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        int a = i;
        int bottom = a % 10;
        if(bottom == 0) continue;
        while(a >= 10){
            a /= 10;
        }
        int top = a;
        
        ans += num[bottom][top].end() - num[bottom][top].begin();
    }
    cout << ans << endl;
    return 0;
}