#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

const ll mod = 1000000007;

int main(){
    string s;
    cin >> s;
    s += 'R';
    int num = 1;
    int idx;
    int ans[s.size()];
    fill(ans, ans + s.size(), 0);
    char c = 'R';
    for (int i = 1; i <= s.size(); i++){
        if(c == s[i]) num++;
        else{
            if(c == 'R'){
                idx = i;
                ans[idx] += num / 2;
                ans[idx-1] += num - (num / 2);
                c = 'L';
                num = 1;
            }else{
                ans[idx-1] += num / 2;
                ans[idx] += num - (num / 2);
                c = 'R';
                num = 1;
            }
        }
    }
    rep(i, s.size()-1){
        cout << ans[i] << " ";
    }cout << endl;
}