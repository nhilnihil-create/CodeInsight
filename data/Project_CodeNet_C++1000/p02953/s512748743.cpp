#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> h(n);
    for(int i=0; i<n; i++) {
        cin >> h.at(i);
    }

    string ans="Yes";
    h.at(0)--;
    if(n>=2){
        if(h.at(0)>h.at(1)) ans="No";
        for(int i=1; i<n-1; i++){
            if(h.at(i-1)!=h.at(i)) h.at(i)--;
            if(h.at(i)>h.at(i+1)) ans="No";
        }
    }
    
    cout << ans << endl;

}