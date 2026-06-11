#include<bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    // cin >> t;
    while (t--) {
        int n;;
        cin>>n;
        string s;
        cin>>s;
        char s1=s[0];
        int i=0;
        vector<char> v;
        for(i=1;i<n;i++){
            char q=s[i];
            if(s1==q){
                continue;
            }
            else{
                //cout<<s1;
                v.push_back(s1);
                s1=s[i];
            }
        }
        if(s1==s[n]){
            continue;
        }
        else{
            //cout<<s[n-1];
            v.push_back(s[n-1]);
            cout<<v.size()<<endl;
        }
    }
    return 0;
}