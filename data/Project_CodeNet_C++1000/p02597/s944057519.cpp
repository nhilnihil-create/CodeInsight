#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;


int main(void){
    int n;
    cin >> n;
    string c;
    cin >> c;
    int sumr=0,sumw=0;
    REP(i,n){
        if(c[i]=='R')
            sumr++;
        else sumw++;
    }
    int a=0,b=n-1,sums=0;
    while(b>a){
        while(c[a]!='W' && a<n){
            a++;
        }
        while(c[b]!='R' && b>=0){
            b--;
        }
        if(b>a){
            swap(c[a],c[b]);
            sums++;
        }
    }

    cout << min(sumr,min(sumw,sums)) << endl;

    return 0;
}