#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long N ,A,B;
    cin >> N >> A>>B;
    long long  C=A+B;
    if(N%C<=A){
        cout <<N/C*A+N%C<<endl;
    }
    else{
        cout<<N/C*A+A<<endl;
    }
}