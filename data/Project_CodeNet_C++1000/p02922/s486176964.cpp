#include<bits/stdc++.h>
using namespace std;
using l1 = long long;

int main(){
    int A, B, outlet=1,cnt=0;
    cin >> A >> B;

    while(outlet < B){
        outlet--;
        outlet += A;
        cnt++;
    }
    cout << cnt << endl;

    return 0;
}