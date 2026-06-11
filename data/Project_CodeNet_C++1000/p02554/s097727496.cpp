#include<bits/stdc++.h>
using namespace std;

static const long long M = (long long) 1e9 + 7ll;

int main(){
    int N;
    cin >> N;

    long long A09, A0, A9, Ano;
    long long A09p, A0p, A9p, Anop;

    Ano=8; A09=0; A0=1; A9=1;

    for(int i=2; i<=N; i++){

        Anop=Ano; A09p=A09; A0p=A0; A9p=A9;

        A09 = (A09p*10 + A9p + A0p) % M;
        A9 = ( A9p*9 + Anop ) % M;
        A0 = ( A0p*9 + Anop ) % M;
        Ano= ( Anop*8 ) % M;

    }

    cout << A09 << endl;

    return 0;
}