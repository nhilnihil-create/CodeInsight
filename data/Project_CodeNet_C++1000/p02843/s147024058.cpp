#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    string x;
    cin >> x;

    if(x.size()<3){
        cout << 0 << endl;
        return 0;
    }
    string t = x.substr(x.size() - 2);
    string e = x.substr(0,x.size()-2);
    int time = atoi(e.c_str());
    int m = atoi(t.c_str());
    if(time*5<m){
        cout << 0 << endl;
    }else{
        cout << 1 << endl;
    }

    return 0;
}