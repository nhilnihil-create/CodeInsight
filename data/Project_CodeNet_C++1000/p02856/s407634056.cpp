#include <bits/stdc++.h>
using namespace std;

int main(){
    int m;
    cin >> m;

    long long int sum = 0;
    long long int digit = 0;
    vector<long long int> d(m), c(m);
    for(int i=0; i<m; i++){
        cin >> d[i] >> c[i];
        sum += d[i] * c[i];
        digit += c[i];
    }

    long long int ans = digit - 1;
    long long int dsum = 0;
    while(sum > 0){
        if(sum >= 10){
            ans += sum / 10;
            dsum += sum % 10;
            sum /= 10;
        }
        else{
            sum += dsum;
            dsum = 0;
            if(sum < 10) break;
        }
    }
    cout << ans << endl;
    return 0;
}