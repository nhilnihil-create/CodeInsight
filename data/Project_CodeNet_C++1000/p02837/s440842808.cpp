#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >> N;
    int i,j,count=0;
    int ans = 0;
    vector<int> A(N);
    vector<vector<int>> x(N);
    vector<vector<int>> y(N);
    for(i=0;i<N;i++){
        cin >> A.at(i);
        for(j=0;j<A.at(i);j++){
            int a,b;
            cin >> a >> b;
            x.at(i).push_back(a);
            y.at(i).push_back(b);
        }
    }
    bool flag = true;
    for(int bit=0;bit<(1<<N);bit++){
        flag = true;
        count = 0;
        for(i=0;i<N;i++){
            if(bit & (1<<i)){
                for(j=0;j<A.at(i);j++){
                    if(bit & (1<<x.at(i).at(j)-1)){
                        if(y.at(i).at(j) == 0){
                            flag = false;
                            break;
                        }
                    }
                    if(!(bit & (1<<x.at(i).at(j)-1))){
                        if(y.at(i).at(j) == 1){
                            flag = false;
                            break;
                        }
                    }
                }
                count ++;
            }
            if(!flag){
                break;
            }
        }
        if(flag){
            ans = max(count,ans);
        }
    }
    
    cout << ans << endl;
}