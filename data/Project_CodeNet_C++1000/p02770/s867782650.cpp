#include<bits/stdc++.h>
using namespace std;
int const nax = 5010;
int k , q, md;
int oldD[nax];
int d[nax];

int n, x;


int query () {
    scanf("%d %d %d", &n, &x, &md);
    x %= md;
    for (int i = 0 ; i < k ; ++ i)
        d[i] = oldD[i] % md;
    long long zero = 0 ;
    long long sum = 0;
    for (int i = 0 ; i < k ; ++ i) {
        if (d[i] == 0) zero ++ ;
        sum += d[i];
    }
    -- n;
    int blockNum = n / k;
    long long last = sum * blockNum ;
    zero *= (long long)blockNum;
    int res = n % k;
    for (int i = 0 ; i < res ; ++ i) {
           if (d[i] == 0 ) zero ++ ;
           last += d[i];
    }
    last += x;
    long long pass = (last / md ) - ((x - 1)/ md);
    printf("%lld\n", n - pass - zero);
}

int main () {
    scanf("%d %d", &k, &q);
    for (int i = 0 ; i < k ; ++ i) {
        scanf("%d", oldD + i);
    }
    while (q --) {
         query() ;
    }
}
/*
    Good Luck
        -Lucina
*/
