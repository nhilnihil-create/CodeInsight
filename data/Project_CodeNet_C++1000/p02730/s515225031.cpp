#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back
#define lp(i,s,f) for(ll i = s; i < ll(f); i++)
#define inF freopen("input.in", "r", stdin);
#define outF freopen("output.in", "w", stdout);
#define endl '\n'
#define MOD 1000000007
#define mm(arr) memset(arr, 0, sizeof(arr))

bool ispal(string s){
    int n = s.size();
    for(int i = 0; i < n/2; i++){
        if(s[i] != s[n - i - 1])return 0;
    }
    return 1;
}
int main(){
    FAST
    string s; cin >> s;
    int n = s.size();
    string s2 = "", s3 = "";
    for(int i = 0; i < n/2; i++){
        s2 += s[i];
    }
    for(int i = (n + 1)/2; i < n; i++){
        s3 += s[i];
    }
    if(ispal(s) && ispal(s2) && ispal(s3)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}
