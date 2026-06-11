//
// Created by elegant-belltree on 15/06/03.
//

#include <iostream>

#define N 123456

using namespace std;

bool not_p[2*N];
int num_p[2*N];

int main(int argc, char *argv[]) {
    int n;

    for (int k = 1; k < 2*N; ++k) {
        if(!not_p[k]){
            for (int i = 2; i*(k+1)-1<2*N; ++i) {
                not_p[i*(k+1)-1]=true;
            }
        }
        num_p[k]+=num_p[k-1]+!not_p[k];
    }
    while (cin>>n && 0<n){
        cout<<num_p[2*n-1]-num_p[n-1]<<endl;
    }
    return 0;
}