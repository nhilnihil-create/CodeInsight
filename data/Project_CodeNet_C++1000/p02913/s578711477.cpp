#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> p;
 
#define MOD 1000000007
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    string S;
    cin >> N >> S;

    vector<map<int, vector<int> > > m(N);

    for(int i = 0; i < N; i++) {
        int a = S[i] - 'a';
        m[0][a].push_back(i);
    }

    int ans = 0;

    bool x = true;

    for(int i = 0; x; i++) {

        x = false;

        int count = 0;
        
        for(auto j = m[i].begin(); j != m[i].end(); j++) {

            if(j -> second.size() < 2) continue;

            x = true;
            
            int front = j -> second[0];

            for(int k = 1; k < j -> second.size(); k++) {

                int back = j -> second[k];
 
                if(front + i < back) {
                    ans = i + 1;
                }
            }

            for(int k = 0; k < j -> second.size(); k++) {
                int d = j -> second[k];
                if(N - 1 <= d) break;
                int a = S[d + 1] - 'a';
                m[i + 1][count * 26 + a].push_back(d + 1);
            }
            count++;
        }
    }

    cout << ans << endl;
}