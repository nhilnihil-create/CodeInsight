#include<iostream>
#include<string.h>
#include<vector>
#include<list>
#include<stdio.h>
#include<math.h>
#include<iomanip>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) range(i,0,b)
#define debug(x) cout << "debug " << x << endl;
using namespace std;

int main(){
    bool prime[250010] = {1,0,0};
    int p[250010];
    int n = 0;
    range(i,2,250010){
        for(int j = i + i; j <= 250010; j+= i){
            prime[j] = true;
        }
    }
    rep(i,250010){
        if(prime[i] == false) n++;
        p[i] = n;
    }
    while(cin >> n, n){
        cout << p[n * 2] - p[n] << endl;
    }
}