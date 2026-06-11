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
    int n,m,l;
    cin>>n>>m>>l;
    if(n+m+l>21)cout<<"bust";
    else cout<<"win";
    
	return 0;
}
