#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    char C[N];

    int NR, nR;

    NR=0;
    nR=0;

    for(int i=0; i<N; i++){
        cin >> C[i];

        if(C[i]=='R'){
            NR++;
        }
    }

    for(int i=0; i<NR; i++){
        if(C[i]=='R') nR++;
    }

    cout << NR-nR << endl;


    return 0;
}