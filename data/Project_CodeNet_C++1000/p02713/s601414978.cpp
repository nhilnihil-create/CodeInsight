#include <bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > vvi;
typedef vector< vector<bool> > vvb;
typedef vector< vector<char> > vvc;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef long long ll;

int gcd(int a,int b){
    int kani=max(a,b);
    int ebi=min(a,b);
    int r=kani%ebi;
    while(r!=0){
        kani=ebi;
        ebi=r;
        r=kani%ebi;
    }
    return ebi;
}

int main(){
    int k;
    cin >> k;
    int sum=0;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            for(int l=1;l<=k;l++){
                sum+=gcd(i,gcd(j,l));
            }
        }
    }
    cout << sum << endl;
    return 0;
}