#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <cfloat>
#include <map>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

const int INF = INT_MAX;

typedef long long LL;
typedef pair<int,int> P;

int main(){
    vector<string> str;
    map<string,int> m;
    string s;
    while(cin>>s){
        str.push_back(s);
        m[s]++;
    }
    int ans1=0;
    string ans1str,ans2str;
    int ans2=0;
    int n=str.size();
    rep(i,n){
        if(str[i].length()>ans2){
            ans2=str[i].length();
            ans2str=str[i];
        }
    }
    rep(i,n){
        if(m[str[i]]>ans1){
            ans1=m[str[i]];
            ans1str=str[i];
        }
    }
    cout << ans1str << " " << ans2str << endl;
    return 0;
}