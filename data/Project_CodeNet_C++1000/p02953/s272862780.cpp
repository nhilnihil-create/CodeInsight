#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> array(n);
    string s = "Yes";
    ll b = 0;
    ll max = -1;
    for(int i=0;i<n;i++){
        ll h;
        cin >> h;
        if(max - h > 1){
            s = "No";
            break;
        }
        if(max < h) max = h;
    }
    cout << s << endl;
}