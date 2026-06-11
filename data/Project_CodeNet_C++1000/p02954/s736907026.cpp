#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define INF 1e9
#define MAXN 100005
#define MAXM 100005
#define MOD 1000000007
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define pii pair<int, int>

vi nums, ans;
int N, cnt = 0;
char c = 'R';
string S;

void solve(){
    rep(i, N){
        if(S[i] == c) {
            cnt++;
        } else {
            nums.push_back(cnt);
            c = S[i];
            cnt = 1;
        }
    }
    nums.push_back(cnt);

    // for(auto v : nums) cout << v << endl;

    ans.resize(N, -1);
    int id = 0, tmp;

    rep(i, N-1){
        if(S[i] == 'R' && S[i+1] == 'L'){
            tmp = nums[id] + nums[id+1];
            if(tmp % 2 == 0){
                ans[i] = tmp/2;
                ans[i+1] = tmp/2;
            } else {
                if(nums[id] > nums[id+1]){
                    ans[i] = (tmp+1)/2;
                    ans[i+1] = (tmp-1)/2;
                } else {
                    ans[i] = (tmp-1)/2;
                    ans[i+1] = (tmp+1)/2;
                }
                if(max(nums[id], nums[id+1]) % 2 == 0) swap(ans[i], ans[i+1]);
            }
            i++;
            id += 2;
        } else {
            ans[i] = 0;
        }
    }

    if(ans[N-1] == -1) ans[N-1] = 0;

    rep(i, N){
        cout << ans[i];
        if(i==N-1) cout << endl;
        else cout << " ";        
    } 
}

int main(){
    cin >> S;
    N = S.size();

    solve();
}
