#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    long long tmp = sqrt(n);
    while(n%tmp!=0){
        tmp--;
    }
    cout << (n/tmp - 1) + (tmp - 1) << endl;
    return 0;
}