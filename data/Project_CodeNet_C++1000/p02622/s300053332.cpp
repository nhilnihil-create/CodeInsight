#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iomanip>
#include <cmath>

#define vi vector<int>
#define tests int t; cin>>t; while(t--)
#define ll unsigned long long
#define vll vector<long long>
#define srt(v) sort(v.begin(), v.end())
#define srtg(v) sort(v.begin(), v.end(), greater<int> ())
#define FOR(k, n) for(int k=0; k<n; k++)



using namespace std;

char nums[10] = { '0','1','2','3','4','5','6','7','8','9' };
char alphsl[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
const ll MOD = 1000000007;
char alphs[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

ll ind(char c) {
    ll i = 0;
    while (c != nums[i]) i++;
    return i;
}

ll sttoin(string s) {

    int n = s.length();
    ll ans = 0, curr = 1;
    for (int i = n - 1; i > -1; i--) {
        ans += curr * ind(s[i]);
        curr *= 10;
    }
    return ans;
}

void solve() {

    string s;
    cin>>s;
    string t;
    cin>>t;
    int cnt=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]!=t[i]) cnt++;
    }
    
    cout<<cnt<<endl;

}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
        solve();



    return 0;
}