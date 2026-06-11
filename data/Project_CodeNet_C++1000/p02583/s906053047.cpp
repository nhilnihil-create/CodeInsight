#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int counter(int n,vector<int>L){
 int c =0;
    sort(L.begin(),L.end());
    REP(i,n){
        FOR(j,i,n){
            FOR(k,j,n){
               if( L.at(i)+L.at(j)>L.at(k)
                   && L.at(i)!=L.at(j)
                   && L.at(j)!=L.at(k)){
                   c++;
               }

            }
        }
    }

    return c;

}

int main(){
 int n;
 cin >>n;
 vector<int>L(n);
 REP (i,n)cin>>L.at(i);

 cout <<counter(n,L)<<endl;
}