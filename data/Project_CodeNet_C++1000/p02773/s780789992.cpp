#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i )

using namespace std;
typedef long long ll;

int main(){
    int N;cin >> N;
    map<string,int> sorted_map;
    int max = 0;
    rep(i,N){
        string tmp;cin >> tmp;
        if (sorted_map[tmp]  > 0){
            sorted_map[tmp]++;
        }
        else {
            sorted_map[tmp] = 1;
        }
        if (sorted_map[tmp] > max){
            max = sorted_map[tmp];
        }
    }

    for(auto x: sorted_map){
        if (x.second == max){
            cout << x.first << endl;
        }
    }

    return 0;
}