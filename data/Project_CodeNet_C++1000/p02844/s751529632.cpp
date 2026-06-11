#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,ans=0;
    string s;
    cin >> n >> s;
    
    for(int i=0;i<1000;i++){
        string pass = to_string(i);
        if(int(pass.size()) == 1) pass = "00" +pass;
        else if(int(pass.size()) == 2) pass = "0" +pass;
        auto pos1 = s.find(pass[0]);
        if(pos1 == string::npos)continue;
        auto pos2 = s.find(pass[1], pos1+1);
        if(pos2 == string::npos)continue;
        auto pos3 = s.find(pass[2], pos2+1);
        if(pos3 == string::npos)continue;
        ans++;
    }
    cout << ans << '\n';
}
