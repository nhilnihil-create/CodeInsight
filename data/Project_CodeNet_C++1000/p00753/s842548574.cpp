#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)

typedef long long ll;

#define N 123456*2

bool isp[N+1];
int s[N+1]={};

int main(void) {
    int n;
    REP(i,N+1){
        isp[i]=1;
    }
    isp[0]=0;
    isp[1]=0;
    FOR(i,2,N/2){
        if (!isp[i]) continue;
        int k=2*i;
        while(k<=N){
            isp[k]=0;
            k+=i;
        }
    }
    FOR(i,1,N){
        s[i] = s[i-1] + isp[i];
    }
    while (cin>>n && n){
        cout << s[2*n] - s[n] << endl;
    }
    
    return 0;
}