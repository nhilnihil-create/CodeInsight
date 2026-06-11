#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<char> S(N);
    for(int i=0; i<N; i++) cin >> S.at(i);
    int Rcnt = 0, Gcnt = 0, Bcnt= 0; 
    for(int i=0; i<N; i++){
        if(S.at(i) == 'R') Rcnt++;
        else if(S.at(i) == 'G') Gcnt++;
        else Bcnt++;
    }
    int64_t rgb = Rcnt;
    rgb *= Gcnt;
    rgb *= Bcnt;
    for(int i=1; i<=(N - 1)/2; i++){
        for(int j=0; 2*i+j<N; j++){
            if (S.at(j) != S.at(i+j) && S.at(i+j) != S.at(2*i+j) && S.at(2*i+j) != S.at(j)){
                rgb--;
            }
        }
    }
    cout << rgb  << endl;
}