#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >>n;
    long long count=0;
    long long val;
    long long min=n;
    for(int i=0; i<n; i++){
        cin >> val;
        if(val <= min){
            count += 1;
            min = val;
        }
    }

    cout << count << endl;
    return 0;


}
