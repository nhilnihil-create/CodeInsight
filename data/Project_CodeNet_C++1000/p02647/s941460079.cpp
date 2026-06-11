#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

#define NMAX 200010

int a[NMAX];
int imos[NMAX];

void reset(int n) {
    for(int i = 0; i < n; i++) imos[i] = 0;
}

int max(int a, int b) {
    if(a > b) return a;
    else return b;
}

int min(int a, int b) {
    if(a > b) return b;
    else return a;
}

int get_int() {
    int res = 0;
    char c = getchar();
    while(c != EOF && c != ' ' && c != '\n') {
        res *= 10;
        res += c - '0';
        c = getchar();
    }
    return res;
}

int main(){

    int n, k;
    n = get_int();
    k = get_int();
    for(int i = 0; i < n; i++) a[i] = get_int();

    for(int itr = 0; itr < k; itr++) {
        int f = 0;
        reset(n+1);
        for(int i = 0; i < n; i++){
            f = (a[i] != n);
            imos[max(0, i - a[i])]++;
            imos[min(n, i + a[i] + 1)]--;
        }
        int acc = 0;
        for(int i = 0; i < n; i++){
            acc += imos[i];
            a[i] = acc;
        }
        if(!f) break;
    }

    for(int i = 0; i < n; i++) printf("%d\n", a[i]);
    return 0;
}
