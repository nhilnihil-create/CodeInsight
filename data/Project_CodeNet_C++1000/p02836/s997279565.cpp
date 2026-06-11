#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define isYES(x) printf("%s\n",(x) ? "YES" : "NO")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){

    string s;
    cin >> s;
    int ans =0;
    //int n=s.length
    rep(i,s.length()/2){
        if(s[i]!=s[s.length()-1-i])
            {s[i]='o';ans++;}
    }
    cout << ans  << endl;
    return 0;

}