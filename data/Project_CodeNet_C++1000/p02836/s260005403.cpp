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
    string s;
    cin>>s;
    int l=s.size(),ans=0;
    rep(i,l/2){
        if(s[i]!=s[l-1-i])ans++;
    }
    cout<<ans;
	return 0;
}
