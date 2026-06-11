#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    string c; cin >> c;

    int ans = 0;
    int i = 0;
    int j = n-1;
    while(i < j){
        while(c[i] == 'R') i++;
        while(c[j] == 'W') j--;
        if(i < j){
            ans++;
            i++;
            j--;
        }
    }

    cout << ans << endl;
}