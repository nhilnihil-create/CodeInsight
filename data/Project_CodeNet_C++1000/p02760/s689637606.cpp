#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int main(void){
    vvi a(3, vi(3));
    for(vi &vr : a) for(int &v : vr) cin >> v;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int b;
        cin >> b;
        for(vi &vr:a)for(int &v:vr)if(b==v) v = 0;
    }
    bool suc = false;
    for(int i=0; i<3; i++){
        if(a[i][0]==0 && a[i][1]==0 && a[i][2]==0) suc = true;
        if(a[0][i]==0 && a[1][i]==0 && a[2][i]==0) suc = true;
    }
    if(a[0][0]==0 && a[1][1]==0 && a[2][2]==0) suc = true;
    if(a[0][2]==0 && a[1][1]==0 && a[2][0]==0) suc = true;
    if(suc)cout << "Yes\n";
    else cout << "No\n";
    return 0;
}