#include <bits/stdc++.h>
using namespace std;

int main(){
    int k, a, b;
    cin >> k >> a >> b;
    vector<int> ran(b-a+1);
    for(int i =0; i<ran.size(); i++) {
        ran.at(i) = a;
        a++;
    }
    bool ans=false;

    for(int i=0; i<ran.size(); i++){
        if(ran.at(i) % k == 0) ans = true;
    }

    if(ans) cout << "OK" << endl;
    else cout << "NG" << endl;
}