#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iomanip>
#include <cmath>
#include <chrono>

#define vi vector<int>
#define tests int t; cin>>t; while(t--)
#define ll long long
#define vll vector<long long>
#define srt(v) sort(v.begin(), v.end())
#define srtg(v) sort(v.begin(), v.end(), greater<int> ())
#define FOR(k, n) for(int k=0; k<n; k++)



using namespace std;
using namespace std::chrono;

char nums[10] = { '0','1','2','3','4','5','6','7','8','9' };
char alphsl[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
const int MOD = 1000000007;
char alphs[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };


bool checkpal(string s, int a, int b){
    int n=b-a+1;
    for(int i=a; i<=b; i++){
        if(s[i]!=s[a+n-i-1]){
            
            return false;
        }
    }
    return true;
}

void solve() {

    string s;
    cin>>s;
    int n=s.length();
    if(checkpal(s, 0, ((n-1)/2)-1)&&checkpal(s, (n+1)/2, n-1)&&checkpal(s, 0, n-1)){
        cout<<"Yes"<<endl;
        return;
    }
    cout<<"No"<<endl;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
        solve();


    return 0;
}