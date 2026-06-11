#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int A;
    cin >> A;
    long long int ans = 0;
    long long int count = 0;
    for(int i = 0; i <= A; i++){
        if(i%3 == 0){
            count += i;
        }
        else if(i%5 == 0){
            count += i;
        }
         ans += i;
    }
    cout << ans - count << endl;
}