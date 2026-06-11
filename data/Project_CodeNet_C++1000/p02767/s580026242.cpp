#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> hai(n);
    for(int i = 0; i< n; i++){
        cin >> hai[i];
    }

    int o = 100000000;
    for(int i = 1; i <= 100;i++){
        int s = 0;
        for(int j = 0; j < n; j++){
            s = s + (hai[j] - i) * (hai[j] - i);
        }
        o = min(o , s);
    }
    cout << o << endl;
    
    
}