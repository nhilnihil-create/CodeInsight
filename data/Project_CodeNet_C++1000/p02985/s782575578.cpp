#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<vector<int> > path;
queue<int> q;
vector<bool> seen;

typedef long long ll;

ll countv = 0;
ll K = 0;


#define MOD (1000000007)

void push(int num, int idx) {
    if(seen[num] != true) {
        q.push(num);
        seen[num] = true;
        //cout << idx<< endl;
        countv = (countv * (K-2 - idx)) %MOD;
    }
}


int main() {
    int N;
    cin >> N >> K;

    path.assign(N, vector<int>());
    seen.assign(N, false);

    for(int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        path[a].push_back(b);
        path[b].push_back(a);
    }

    seen[0] = true;
    countv = K;



    for(int i = 0; i < path[0].size(); i++) {
        if(seen[path[0][i]] == true) continue;
        seen[path[0][i]] = true;
        q.push(path[0][i]);
        countv = (countv * (K - i - 1)) % MOD;
        //cout << countv << endl;
    }
    
    while(q.size() >= 1) {
        int current = q.front();q.pop();
        int idx = 0;
        for(int i = 0; i < path[current].size(); i++) {
            if(seen[path[current][i]] == true) continue;
            
            push(path[current][i], idx++);
        }
    }

    cout << countv << endl;

}
