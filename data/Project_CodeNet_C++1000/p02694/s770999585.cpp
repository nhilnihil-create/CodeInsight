#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
#define DEBUG 0
#define INF (1LL<<50)
#define MOD 1000000007
#define rev(v) reverse(v.begin(), v.end());

bool comp(int a, int b){
    return (a<b);
}

int main(){
    long long x; cin >> x;
    long long n = 100;
    int cnt = 0;
    while(n<x){
        n+=n/100;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}