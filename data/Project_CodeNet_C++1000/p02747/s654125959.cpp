#include <iostream>
#include <string>

using namespace std;

void solve(){
    string s;
    cin>>s;
    int sz = s.size();
    if(sz%2){
        cout<<"No\n";
        return;
    }
    for(int i = 0; i < sz; i++){
        if(s[i%2]!="hi"[i%2]){
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
}

int main() {
    solve();
    return 0;
}