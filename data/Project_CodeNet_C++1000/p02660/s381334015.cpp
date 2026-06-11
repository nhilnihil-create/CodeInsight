#include<bits/stdc++.h>
using namespace std;
int main(){
    int64_t N;
    cin >> N;
    vector<int> div;

    if(N==1){
        cout << 0 << endl;
        return 0;
    }
    int64_t n=N;

    for(int64_t i=2; i*i<=N; i++){
        int times=0;
        while(n%i == 0){
            n = n/i;
            times++;
        }
        if(times != 0){
            div.push_back(times);
        }
    }
    if(n != 1){
        div.push_back(1);
    }

    int ans=0;
    for(int i=0; i<div.size(); i++){
        int check=1;
        int plus=0;
        while(div.at(i) >= check){
            div.at(i) -= check;
            check++;
            plus++;
        }
        ans += plus;
    }
    cout << ans << endl;
}
