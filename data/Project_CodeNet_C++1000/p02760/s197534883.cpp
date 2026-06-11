#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;

int a[5][5], b[5][5];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> a[i][j];
        }
    }
    int x;
    cin >> x;
    map<int, int> mp;
    while(x--){
        int n;
        cin >> n;
        mp[n] = 1;
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(mp[a[i][j]]) b[i][j] = 1;
        }
    }
    bool found = 0;
    for(int i = 0; i < 3; i++){
        int c = 0;
        for(int j = 0; j < 3; j++){
            if(b[i][j]) c++;
        }
        if(c == 3) found = 1;
        c = 0;
        for(int j = 0; j < 3; j++){
            if(b[j][i]) c++;
        }
        if(c == 3) found = 1;
    }
    int c = 0;
    for(int i = 0; i < 3; i++) if(b[i][i]) c++;
    if(c == 3) found = 1;
    c = 0;
    for(int i = 0, j = 2; i < 3; i++, j--) if(b[i][j]) c++;
    if(c == 3) found = 1;
    if(found) cout << "Yes";
    else cout << "No";



    return 0;
}
