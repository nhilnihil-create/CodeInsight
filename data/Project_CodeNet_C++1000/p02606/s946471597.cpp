#include <bits/stdc++.h>
using namespace std;
int n;
int f(int x){
    return x/n;
}

int main() {
    int l,r;
    cin>>l>>r>>n;
    cout<<f(r)-f(l-1)<<"\n";
	return 0;
}
