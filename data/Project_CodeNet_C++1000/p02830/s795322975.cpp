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
    int n;
    string a,b,c="";
    cin>>n>>a>>b;
    rep(i,n){
        c.push_back(a[i]);
        c.push_back(b[i]);
    }
    cout<<c;
	return 0;
}
