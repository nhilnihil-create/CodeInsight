// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

int main(){
    int N, M;
    cin >> N >> M;
    priority_queue<P> que1;
    priority_queue<int> que2;

    rep(i, N){
        P tmp;
        cin >> tmp.first >> tmp.second;
        tmp.first = -tmp.first;
        que1.push(tmp);
    }

    int sum = 0, work_n = 0;

    for(int i = 1; i <= M; i++){
        while(!que1.empty()){
            P tmp;
            tmp = que1.top();
            int a = -1 * tmp.first, b = tmp.second;
            if(a <= i){
                que1.pop();
                que2.push(b);
            } 
            else break;
        }
        if(!que2.empty()){
            sum += que2.top();
            que2.pop();
        }
    }
    
    cout << sum << endl;
}