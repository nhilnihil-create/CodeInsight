#include <bits/stdc++.h>
#define rp(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
using G=vector<vector<int>>;

int main(){
    int h,w,n;
    cin >> h >> w >> n;
    int m=max(h,w);
    if(n%m==0) cout << n/m << endl;
    else cout << n/m+1 << endl;
}