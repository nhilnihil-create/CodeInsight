#include<bits/stdc++.h>

using namespace std;

int n;
int main()
{
    cin >> n;
    vector<vector<int>> a(n, vector<int> (n - 1));
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n - 1; j ++)
            cin >> a[i][j], a[i][j] --;
    vector<int> q1;
    vector<int> c(n, 0);
    for(int i = 0; i < n; i ++){
        int x = a[i][0];
        if(a[x][0] == i) q1.push_back(i);
    }
    int res = 0;
    while(!q1.empty()){
        res ++;
        vector<int> q2;
        for(auto x: q1){
            c[x] ++;
            if(c[x] < n - 1){
                int y = a[x][c[x]];
                if(a[y][c[y]] == x){
                    q2.push_back(x);
                    q2.push_back(y);
                }
            }
        }
        q1 = q2;
    }
    for(int i = 0; i < n; i ++){
        if(c[i] < n - 1) res = -1;
    }
    cout << res << "\n";
}
