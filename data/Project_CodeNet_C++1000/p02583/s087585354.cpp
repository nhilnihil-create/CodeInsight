//  main.cpp
//  CppTest

#include <iostream>
#include <set>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {

    // cinを高速にするためのおまじない
    cin.tie(0);
    ios::sync_with_stdio(false);

    /////////////////////
    // Write code below /
    int N,count = 0;
    unsigned long long int L[110];
    cin >> N;
    for(int i = 0; i < N ; i++) cin >> L[i];


    sort(L, L+N);
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            for(int k=j+1;k<N;k++){
                if(L[i]!=L[j] && L[j]!=L[k]){
                    if(L[i] + L[j] > L[k]) count++;
                }
            }
        }
    }
    cout << count << endl;
    /////////////////////

    return 0;
}
