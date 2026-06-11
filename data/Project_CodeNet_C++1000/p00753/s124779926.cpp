
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
#include <utility>
#include <set>
#include <map>
#define INF 1000000000
#define rep(i,n) for(int i =0;i<n;i++)
using namespace std;
typedef long long int ll;

vector<ll> P(250000,0);

void era(){
    for (int i=2; i<250000; i++) {
        if(P[i]==0) continue;
        int j=i;
        while(j<250000) {
            j+=i;
            if(j>=250000)break;
            P[j]=0;
        }
    }
}


int main(){
    rep(i,P.size()) P[i]=i;
    era();
    for (;;) {
        int n;
        cin >> n;
        if(!n)break;
        ll ans=0;
        for (int i=n+1; i<=2*n; i++) {
            if (P[i]!=0) {
                ans++;
            }
        }
        cout << ans <<endl;
    }
    return 0;
}