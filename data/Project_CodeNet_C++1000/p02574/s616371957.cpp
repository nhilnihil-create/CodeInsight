#include<bits/stdc++.h>
using namespace std;
const int MX=1e6+5;
set<int> s;
int n,x,k,y,f[MX];
bool b;
int main()
{
    for(int i=0; i<MX; i++) f[i]=i;
    for(int i=2; i*i<MX; i++){
        if(f[i]!=i) continue;
        for(int j=i*i; j<MX; j+=i){
            if(f[j]==j) f[j]=i;
        }
    }
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        y=__gcd(y,x);
        while(x>1){
            k=f[x];
            if(s.find(k)!=s.end()) b=true;
            s.insert(k);
            while(x%k==0) x/=k;
        }
    }
    if(!b){
        cout << "pairwise coprime";
        return 0;
    }
    if(y>1) cout << "not coprime";
    else cout << "setwise coprime";
    return 0;
}