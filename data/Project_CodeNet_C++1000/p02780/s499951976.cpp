#include <string>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
 
double expValue(int val){
    double ans = 0;
    for(int i = 0; i <= val; i++) ans += i;
    return ans / val;
}
 
int main()
{
    int n, k;
    cin >> n >> k;
    long double tot = 0;
    vector<double> table(200005);
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        table[i] = expValue(a);
    } 
    for(int i = 1; i <= k; i++) tot += table[i];
    long double max = tot;
    for(int i = 1; i + k <= n; i++){
        tot -= table[i];
        tot += table[i+k];
        if(max < tot) max = tot;
    }
    printf("%Lf", max);
}
