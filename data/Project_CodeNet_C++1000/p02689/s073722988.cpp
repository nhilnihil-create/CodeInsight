#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n>>m;
    vector<int> height(n);
    vector<int> max_height(n,0);
    for(int i=0; i< n; i++){
        int h;
        cin >> h;
        height.at(i) = h;
    }
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        max_height.at(a-1) = max(max_height.at(a-1), height.at(b-1));
        max_height.at(b-1) = max(max_height.at(b-1), height.at(a-1));
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        if(height.at(i) > max_height.at(i)){
            ans++;
        }
    }
    cout << ans << endl;
}