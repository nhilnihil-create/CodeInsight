#include<bits/stdc++.h>

using namespace std;
int main(){
    int n,i;
    cin >> n;
    double sum = 0,a;
    for(i=0; i<n; i++){
       cin >> a;
       sum+=(1.0/a);
    }
    sum=(1.0)/sum;
    cout << fixed << setprecision(10) << sum << endl;
    return 0;
}