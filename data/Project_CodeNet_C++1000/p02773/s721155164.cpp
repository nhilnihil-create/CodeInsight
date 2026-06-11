#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<string> S(N);
    for(int i=0; i<N; i++) cin >> S.at(i);
    map<string, int> cnt;
    for(int i=0; i<N; i++) cnt[S.at(i)]++;
    int max_cnt = 0;
    for(auto itr=cnt.begin(); itr!=cnt.end(); itr++){
        if(max_cnt < itr->second) max_cnt = itr->second;
    }
    for(auto itr=cnt.begin(); itr!=cnt.end(); itr++){
        if(itr->second == max_cnt) cout << itr->first << endl;
    }
}