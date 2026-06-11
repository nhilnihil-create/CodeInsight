#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
#define DEBUG 0
#define INF (1LL<<50)
#define MOD 1000000007

bool comp(int a, int b){
    return (a<b);
}

int main(){
    string flag = "APPROVED";
    int n; cin >> n;
    vector<int> a(n);
    REP(i,0,n) cin >> a[i];
    REP(i,0,n){
        if(a[i]%2==0){
            if(a[i]%3!=0){
                if(a[i]%5!=0){
                    flag = "DENIED";
                }
            }
        }
    }
    cout << flag << endl;
    return 0;
}