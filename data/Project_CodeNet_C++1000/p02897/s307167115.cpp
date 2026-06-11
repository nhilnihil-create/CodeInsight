#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    if(n%2){
        double ans = (n/2 + 1)/(double)n;
        printf("%0.10lf\n", ans);
    }else{
        double ans = 0.5;
        printf("%0.10f\n", ans);
    }

    return 0;
    
    
}
