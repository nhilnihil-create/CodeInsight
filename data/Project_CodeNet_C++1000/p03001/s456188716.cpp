#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    double w,h;
    int x,y;cin>>w>>h>>x>>y;
    int cc = 0;
    if(w/2==x && h/2==y)cc=1;
    cout<<setprecision(10)<<w*h/2<<" " <<cc<<endl;
	return 0;
}