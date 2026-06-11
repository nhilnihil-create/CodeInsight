#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    long long n,k;
    cin >> n >>k;
    cout<<min(n%k,abs(n%k-k));
}
