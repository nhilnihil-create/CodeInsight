#include <bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > vvi;
typedef vector< vector<bool> > vvb;
typedef vector< vector<char> > vvc;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef long long ll;

int main(){
    int N;
    cin >> N;
    map<string,int> mp;
    for(int i=0;i<N;i++){
        string s;
        cin >> s ;
        mp[s]++;
    }
    int ans=0;
    for(auto x:mp){
        ans++;
    }
    cout << ans << endl;
    return 0;
}