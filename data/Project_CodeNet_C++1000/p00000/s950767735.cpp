#include <iostream>
#include <cstdio>
using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)

int main(){
    int i, j;
    FOR(i, 1, 10){
        FOR(j, 1, 10){
            printf("%dx%d=%d\n", i, j, i*j);
        }
    }
    return 0;
}