#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
    long long n,a,b,i,ac,bc;
    cin>>n>>a>>b;
    i=abs(a-b);
    ac=a-1;bc=n-b;
    if(i%2==0)cout<<i/2;
    else cout<<(b-a+1)/2+min(ac,bc);
    
	return 0;
}
