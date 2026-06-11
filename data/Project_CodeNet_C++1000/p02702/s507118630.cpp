#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> mod(2019,0);
    string s;
    cin >> s;
    int n = s.size();
    int x=0;
    int keta=1;
    mod.at(0)++;
    for(int i=0; i<n; i++){
        x += (s.at(n-1-i) -'0') * keta;
        keta = (keta*10) %2019;
        //cout << x <<endl;
        mod.at(x%2019)++;
    }
    
    int ans=0;
    for(int i=0; i<2019; i++){
        if(mod.at(i) >= 2) ans += mod.at(i)*(mod.at(i)-1)/2;
    }
    cout << ans << endl;
}
