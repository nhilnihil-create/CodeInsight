#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> sunuke(n, 0);
    for(int i=0;i<k;i++){
        int d;
        cin >> d;
        for(int j =0; j< d; j++){
            int a;
            cin >> a ;
            sunuke[--a]++;
        }
    }
    int ans = 0;
    for(auto e: sunuke){
        if(e == 0) ans ++;
    }
    cout << ans << endl;
}