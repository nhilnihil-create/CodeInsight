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
    string s;
    int k;
    cin >> k >> s;
    if(s.size() <= k){
        cout << s << endl;
        return 0;
    }else{
        string ans;
        ans = s.substr(0, k);
        ans += "...";
        cout << ans << endl;
        return 0;
    }
	return 0;
}
