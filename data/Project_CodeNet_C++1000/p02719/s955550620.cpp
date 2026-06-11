#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    unsigned long long n,k;
    
    cin >> n >>k;

    cout << min(n%k,k-n%k);

}