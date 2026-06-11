#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include<numeric>
using namespace std;
using P = pair<int, int>;
#define rep(i,n) for(int i=0; i<(n);i++)
typedef long long ll;


int main(){
    int n; cin >> n;
    vector<string> s(n);
    vector<string> copy;
    int ans=0;
    rep(i,n){
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    rep(i,n){
        if(s[i] != s[i+1]) ans++;
    }
    cout << ans << endl;
	return 0;
}
