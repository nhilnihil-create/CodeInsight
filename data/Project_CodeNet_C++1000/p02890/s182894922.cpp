#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int N;
    while(cin >> N){
        map<int, int> mp;
        for(int i=0;i<N;i++){
            int t; cin >> t;
            if(!mp.count(t)) mp[t] = 0;
            ++mp[t];
        }
        vector<int> cnt;
        for(auto it : mp){
            cnt.push_back(it.second);
        }
        sort(cnt.begin(), cnt.end());
        int b = cnt.size();
        vector<int> kind(N, 0);
        for(int i=1;i<=N;i++){
            while(b > 0 && cnt[cnt.size()-b] < i) --b;
            kind[i-1] = b;
        }
        int last = 0;
        vector<int> res(N);
        for(int i=N-1;i>0;i--){
            while(kind[last] >= i+1) ++last;
            res[i] = last;
            int up = last;
            for(int j=last;j<N&&up;j++){
                int add = min(i - kind[j], up);
                kind[j] += add;
                up -= add;
            }
        }
        res[0] = N;
        for(auto t : res) cout << t << endl;
    }
}