#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
    int a,b;
    cin>>a>>b;
    if((a+b)&1)cout<<"IMPOSSIBLE";
    else cout<<(a+b)/2;
	return 0;
}
