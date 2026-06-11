#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int x;
    cin >> x;

    vector<long long int> exp5(1000);
    for(long long int i=0; i<1000; i++){
        exp5[i] = i * i * i * i * i;
        //cout << exp5[i] << endl;
    }

    for(int i=0; i<1000; i++){
        long long int b5 = abs(exp5[i] - x);
        int l = lower_bound(exp5.begin(), exp5.end(), b5) - exp5.begin();
        int r = upper_bound(exp5.begin(), exp5.end(), b5) - exp5.begin();
        //cout << b5 << " " << l << " " << r << endl;
        if(r - l == 1){
            if(x > exp5[i]) l *= -1;
            cout << i << " " << l << endl;
            return 0;
        }
    }
    return 0;
}