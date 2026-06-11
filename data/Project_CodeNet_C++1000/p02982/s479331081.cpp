#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main(){
    int n , d, tempi, cnt = 0;
    vector<vector<int> > ans;
    cin >> n >> d;
    for(int i=0; i < n; ++i){
        vector<int> temp;
        for(int j = 0; j < d; ++j){
            cin >> tempi;
            temp.push_back(tempi);
        }
        ans.push_back(temp);
    }
    for(int i = 0;i < n-1; ++i){
        for(int j = i+1; j<n; ++j){
            double k = 0;
            for(int l = 0; l < d; ++l){
                k += (ans[i][l]-ans[j][l])*(ans[i][l]-ans[j][l]) ;
            }
            k = sqrt(k);
            if(floor(k)== k){
                ++cnt;
            }
        }
    }
    cout<<cnt;
    return 0;
}
