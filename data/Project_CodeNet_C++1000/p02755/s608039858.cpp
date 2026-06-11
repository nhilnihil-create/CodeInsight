#include<bits/stdc++.h>
using namespace std;

int main(){
    double a, b; cin >> a >> b;
    int ans=0;
    int dis=1;
    bool flg = true;
    while(true){
        if(floor(dis * 0.08) == a && floor(dis*0.1) == b){
            ans = dis; break;
        }
        if(dis > 1000){
            flg = false; break;
        }
        dis++;
    }
    if(flg)
        cout<< ans << endl;
    else
    {
        cout << -1 << endl;
    }
    
    return 0;
}