#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i )
typedef std::pair<int,int> pint;

using namespace std;
typedef long long ll;

int main(){
    int K; cin >> K;
    int N; cin >> N;
    vector<int> list;
    int max = 0;
    rep (i,N){
        int tmp;
        cin >> tmp;
        list.push_back(tmp);
    }
    rep (i,N-1){
        int tmp;
        tmp = list[i + 1] - list[i];
        if (tmp > max){
            max = tmp;
        }
    }
    int last = (K - list[N - 1]) + list[0];
    if (last > max){
        max = last;
    }
    cout << K - max << endl;
    return 0;
}