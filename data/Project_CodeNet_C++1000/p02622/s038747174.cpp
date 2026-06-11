#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;

int main(){
    string a,b;
    int count = 0;
    cin >> a >> b;
    rep(i,a.length()){
        if(a[i] != b[i])count++;
    }
        cout << count << endl;
    return 0;
}