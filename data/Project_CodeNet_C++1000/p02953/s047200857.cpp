#include<iostream>
#include<vector>
#include<algorithm>
#define Fast ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    Fast;
    int n;
    cin >> n;
    vector<int> stairs;
    int i;
    for(i=0; i<n; i++){
        int x;
        cin >> x;
        stairs.push_back(x);
    }
    bool ok = true;
    int h = stairs[0];
    for(i=1; i<n; i++){
        if(stairs[i]<(h-1)){
            ok = false;
            break;
        }
        else{
            h = max(h, stairs[i]);
        }
    }
    /*for(i=1; i<n; i++){
        if(stairs[i]<stairs[i-1]){
            ok = false;
            break;
        }
    }*/
    if(ok) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}