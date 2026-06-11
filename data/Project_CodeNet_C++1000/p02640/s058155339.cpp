#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e6+5;
int main() {
    int x,y;cin>>x>>y;
    for(int i=0;i<=x;i++) {
    	if(i*2+(x-i)*4==y)
    		return 0*puts("Yes");
    }
    puts("No");
    return 0;
}