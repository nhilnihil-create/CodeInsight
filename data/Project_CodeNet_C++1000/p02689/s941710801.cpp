#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, m, h[100100], i, j, ans=0;
    vector<long long> con[100100];
    bool judge;
    cin >> n >> m;
    for(i=0;i<n;i++){
        cin >> h[i];
    }
    for(i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        a--;b--;
        con[a].push_back(b);
        con[b].push_back(a);
    }
    for(i=0;i<n;i++){
        judge=true;
        for(auto x : con[i]){
            if(h[x]>=h[i]){
                judge=false;
                break;
            }
        }
        if(judge){
            ans++;
        }
    }
    cout << ans <<endl;
    return 0;
}