#include<bits/stdc++.h>
using namespace std;
#define itn int

int main(void){
    long long n,a,b;
    cin >> n >> a >> b;
    
    long long sum = 0;
    if(a % 2 == b % 2)sum = (b-a)/2;
    else {
        sum = min(a-1,n-b)+((b-a-1)/2)+1;
    }
    cout << sum << endl;
}