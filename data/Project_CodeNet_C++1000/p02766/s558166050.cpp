#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    int digitNum = 0;
    while(n>0){
        int tmp = n%k;
        n-=tmp;
        n/=k;
        digitNum++;
    }
    cout << digitNum << endl;
    return 0;
}