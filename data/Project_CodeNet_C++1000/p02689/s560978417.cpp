#include <iostream>
using namespace std;

#include <string>
#include <vector>
int main(){
    int n,m; cin >> n >> m;
    vector<int> h(n);
    vector<vector<int>> tenbou(n,vector<int>());
    for(int i=0; i<n; i++) cin >> h[i];
    int ina,inb;
    for(int i=0; i<m; i++){
        cin >> ina >> inb;
        tenbou[ina-1].push_back(inb-1);
        tenbou[inb-1].push_back(ina-1);
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        int flag = 1;
        for(int j=0; j<tenbou[i].size(); j++){
            if(h[tenbou[i][j]]>=h[i]){
                flag=0;
                break;
            }
        }
        if(flag) ans++;
    }
    cout << ans << endl;
}