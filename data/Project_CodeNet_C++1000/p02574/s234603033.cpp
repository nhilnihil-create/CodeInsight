#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)1e6;
int d[MAXN+1];
bool prime[MAXN+1];
int n;
 
void sieve(){
    memset(prime,true,sizeof(prime));
    for(int p=2; p*p<=MAXN; p++){
        if(prime[p]){
            for(int i=p*p; i<=MAXN; i+=p){
                prime[i] = false;
                d[i] = p;
            }
        }
    }
    d[1]=1;
    for(int i=2; i<=MAXN; i++) if(prime[i]) d[i] = i;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int a[n]; for(int i=0; i<n; i++) cin >> a[i];
    int b[n]; for(int i=0; i<n; i++) b[i] = a[i];
    sieve();
    bool pairwise = true;
    map<int,int> m;
    for(int i=0; i<n; i++){
        set<int> s;
        while(a[i]>1){
            s.insert(d[a[i]]);
            a[i]/=d[a[i]];
        }
        for(auto& a : s){
            m[a]++;
            if(m[a]>1){
                pairwise = false;
                break;
            }
        }
        if(!pairwise) break;
    }
    if(pairwise) cout << "pairwise coprime" << endl;
    else{
        int curr = gcd(b[0],b[1]);
        for(int i=2; i<n; i++){
            curr = gcd(curr,b[i]);
        }
        if(curr==1) cout << "setwise coprime" << endl;
        else cout << "not coprime" << endl;
    }
}