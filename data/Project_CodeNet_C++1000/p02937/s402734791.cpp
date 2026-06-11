#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;
typedef priority_queue<int, vector<int>, greater<int>> PQ;
const int MOD = 1000000007;

const int maxv = 100005;


string s, t;
map<char, vector<int>> counter;
vector<int> c;
bool isOK(int mid, int key){
    if (key < c[mid]) return true;
    else return false; 
}

int binary_search(int key){
    int ng = -1;
    int ok = c.size();
    
    while(abs(ok-ng)>1){
        int mid = (ok+ng) / 2;

        if(isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}


int main(){
    cin >> s >> t;

    rep(i,s.size()){
        int index = i+1;
        counter[s[i]].push_back(index);
    }

    ll ans = 0;
    int prev_index;
    rep(i, t.size()){
        char ch = t[i];
        if (counter[ch].empty()){
            cout << -1 << endl;
            return 0;
        }
        if (i == 0) {
            prev_index = counter[ch][0];
            ans = prev_index;
            //cout << prev_index << endl;
            continue;
        }
        else{
            int size = counter[ch].size();
            vector<int> c = counter[ch];
            int next_index;
            if (prev_index >= c[size-1]){
                next_index = c[0];
            }
            else{
                //int result = binary_search(prev_index);
                int result = upper_bound(c.begin(), c.end(), prev_index) - c.begin();
                next_index = c[result];
                //cout << next_index << endl;
            }

            //int result = binary_search(prev_index, counter[t[i]]);
            //cout << result << endl;
            //int next_index;
            /*
            if (result != counter[t[i]].size()){
                next_index = counter[t[i]][result];
            }
            else{
                next_index = counter[t[i]][0];
            }
            */
            /*
            for (auto c : counter[t[i]]){
                if (c > prev_index){
                    next_index = c;
                    break;
                } 
            }
            */
            //cout << next_index << endl;
            if (prev_index < next_index){
                ans += next_index - prev_index;
            }else{
                ans += next_index + (s.size() - prev_index);
            }
            prev_index = next_index;
        }
    }
    cout << ans << endl;
}