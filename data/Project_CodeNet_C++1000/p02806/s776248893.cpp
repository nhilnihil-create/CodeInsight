#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<numeric>
#include<utility>

using namespace std;

typedef long long int ll;
const int INF = 1<<30;
const long long LINF = 1LL<<60;

int main(){
    int n, ans = 0;
    cin >> n;
    vector<string> s(n);
    vector<int> t(n);
    for(int i = 0; i < n; i++){
        cin >> s[i] >> t[i];
    }
    string x;
    cin >> x;
    int c = 0;
    while(x != s[c]){ c++; }
    c++;
    while(c < n){
        ans += t[c];
        c++;
    }
    cout << ans << endl;
    return 0;
}
