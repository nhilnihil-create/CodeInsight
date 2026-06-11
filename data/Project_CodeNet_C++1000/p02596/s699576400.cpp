#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <random>
#include <queue>


using namespace std;

// ans = a ? b : c; // to simplify: if (a) ans = b; else ans = c;
// ans += val; // to simplify: ans = ans + val; and its variants
// index = (index + 1) % n; // index++; if (index >= n) index = 0;
// index = (index + n - 1) % n; // index--; if (index < 0) index = n - 1;
// int ans = (int)((double)d + 0.5); // for rounding to nearest integer
// ans = min(ans, new_computation); // min/max shortcut
// alternative form but not used in this book: ans <?= new_computation;
// some code use short circuit && (AND) and || (OR)

typedef long long ll; // comments that are mixed in with code
typedef pair<int, int> ii; // are aligned to the right like this
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
#define INF 1000000000
#define M_PI 3.14159265358979323846

void printVector2d(vector<vector<int>> a){
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"end"<<endl;
}

void printVector(vector<int> a){
    for(int i=0;i<a.size();i++){
        int curr_num = a[i]+1;
        cout<<curr_num<<" ";
    }
    cout<<endl;
}

void printVectorTwo(vector<int> a){
    for(int i=0;i<a.size();i++){
        int curr_num = a[i];
        cout<<curr_num<<" ";
    }
    cout<<endl;
}

void printVectorPair(vector<pair<int,int>> a){
    for(int i=0;i<a.size();i++){
        cout<<"Total "<<i<<": "<<a[i].first<<" "<<a[i].second<<endl;
    }
}

void printMap(map<char, int> mp){
    for(auto x:mp){
        cout<<x.first<<": "<<x.second<<endl;
    }
}

void printMapVec(map<int, vector<int>> mpV){
    for(auto x:mpV){
        cout<<x.first<<": ";
        for(auto y:x.second){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}

void printQueue(queue<char> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<" ##### ";
}

void solve(){
    int K, ans;

    cin>>K;

    ll curr_checker  = 0;
    ans = 0;

    if(K%2==0 || K%5==0){
        cout<<-1<<endl;
        return;
    }

    bool found_ans = false;
    while(!found_ans){
        curr_checker = (curr_checker*10 + 7)%K;
        if(curr_checker==0){
            found_ans = true;
//            cout<<curr_checker<<endl;
        }
        ans++;
        if(ans>pow(10,7)){
            ans = -1;
            break;
        }
    }
    cout<<ans<<endl;
}

int main() {
    //solve();
    int T;
//    cin >> T;
    T=1;
    for (int case_num = 1; case_num <= T; case_num++) {
//        cout<<"Case #"<<case_num<<": ";
        solve();
    }
    return 0;
}