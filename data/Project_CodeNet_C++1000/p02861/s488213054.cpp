#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <algorithm>

double dist(vector<int> p1, vector<int> p2){
    int dx = p1[0] - p2[0];
    int dy = p1[1] - p2[1];
    return pow( dx*dx + dy*dy ,0.5);
}

int main(){

    int N; cin>>N;
    vector<vector<int>> Map(N, vector<int>(2));
    for(int n=0; n<N; n++) cin>>Map[n][0]>>Map[n][1];

    // 順列全探索
    vector<int> ptn(N); for(int n=0; n<N; n++) ptn[n]=n;
    double all_dist = 0;
    int cnt=0;
    do{
        double cnt_dist =0;
        for(int i=1; i<N; i++) cnt_dist += dist(Map[ptn[i-1]], Map[ptn[i]]);
        all_dist += cnt_dist;
        cnt++;
    } while(next_permutation(ptn.begin(), ptn.end()));

    cout <<fixed<<setprecision(10)<<(all_dist/cnt)<< endl;
}