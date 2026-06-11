#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i < (int)n;++i)

int main() {
    int a[5];
    rep(i,5)cin>>a[i];
    cout<<(a[2]-a[0])*60 + (a[3]-a[1])-a[4]<<endl;
	return 0;
}

