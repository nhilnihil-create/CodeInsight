#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int>h(n);

    for(int i=0; i<n; i++){
        cin >> h[i];
        if(i>0 && i<n){
            if(h[i-1]<h[i]) h[i]--;
        }
    }

    for(int i=0; i<n-1; i++){
        if(h[i]>h[i+1]){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}