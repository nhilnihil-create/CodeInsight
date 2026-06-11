#include <bits/stdc++.h>
#define ll long long int
#define forr(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
#define oo 100000000000000000
using namespace std;

bool pairWise(vector<int> &v){
    unordered_map<int,int> m;
    int n = v.size();
    for(int i=n-1;i>=0;i--){
        int x = v[i];
        for(int j=2;j*j<=x;j++){
            if(x%j==0){
                if(m[j]>0) return false;
                else m[j]++;
                while(x%j==0) x = x/j;
            }
        }
        if(x!=1){
            if(m[x]>0) return false;
            else m[x]++;
        }
    }
    return true;
}


bool g1(vector<int> &v){
    int g = 0;
    for(auto &i: v) g = __gcd(g , i);
    return (g==1);
}

void _sol(){
    int n; cin >> n;
    vector<int> v(n);
    for(auto &i: v ) cin >> i;
    if(pairWise(v)) cout << "pairwise coprime";
    else if(g1(v)) cout << "setwise coprime";
    else cout << "not coprime";

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    _sol();
}
