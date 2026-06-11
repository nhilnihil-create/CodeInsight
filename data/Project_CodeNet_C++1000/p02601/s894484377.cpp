#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    int a,b,c,k,i=0;
    cin>>a>>b>>c>>k;
    while(a>=b&&k){
        b*=2;
        k--;
    }
    rep(i,k)c*=2;
    if(b<c&&a<b)cout<<"Yes";
    else cout<<"No";
	return 0;
}
