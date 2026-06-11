#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int a, v, b, w, t;
    cin >> a >> v >> b >> w >> t;
    
    long long initial_distance = abs(b - a);
    if(v == w || v < w){
        cout << "NO" << endl;
        return 0;
    }
    
    double time_needed = (double)initial_distance/(v - w);
    if(time_needed <= t){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    
    return 0;
}
