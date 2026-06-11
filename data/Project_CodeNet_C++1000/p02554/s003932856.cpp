#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;
ll n;

int main() {
	// your code goes here
	cin >> n;
    ll U=1;;
    ll A = 1;
    ll A_B= 1;
    for(int i=0;i<n;i++){
        U = (U%M*10%M)%M;
        A=(A%M*9%M)%M;   // is B
        A_B=(A_B%M*8%M)%M;

    }
   
    ll unio = ((2*A - A_B)%M+M)%M;
    cout <<  ((U-unio)%M+M)%M;
}