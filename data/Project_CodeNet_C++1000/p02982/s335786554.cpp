#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,d;
    cin >> n >> d;
    vector<vector<int>> x(n,vector<int>(d));
    for(int i=0; i<n; i++){
        for(int j=0; j<d; j++){
            cin >> x.at(i).at(j);
        }
    }
    double dis = 0;
    int ans = 0;
    for(int i=0; i<=n; i++){
        for(int j=1; j<i; j++){
            for(int k=0; k<d; k++){
                dis += abs((x.at(i-1).at(k) - x.at(j-1).at(k))*(x.at(i-1).at(k) - x.at(j-1).at(k)));
            }
            dis = sqrt(dis);
            int nbool = dis;
            if(dis == nbool){
                ans += 1;
            }
            dis = 0;
        }
    }
    cout << ans << endl;
}