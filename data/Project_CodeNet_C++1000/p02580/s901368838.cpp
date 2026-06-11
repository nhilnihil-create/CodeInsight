#include <bits/stdc++.h>
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define MOD 1000000007
using namespace std;
int main(){
    int H, W, M; cin >> H >> W >> M;
    int rows[H] = {0};
    int cols[W] = {0};
    set<pair<int,int>> seen;
    for(int i = 0; i < M; i++){
        int h,w;
        cin >> h >> w;
        rows[h-1]++;
        cols[w-1]++;
        seen.insert(pair<int,int> (h-1, w-1));
    }
    int rowMax = *max_element(rows, rows+H);
    int colMax = *max_element(cols, cols+W);
    vector<int> rowMaxes;
    vector<int> colMaxes;
    for(int i = 0; i < H; i++){
        if(rows[i] == rowMax) rowMaxes.push_back(i);
    } 
    for(int i = 0; i < W; i++){
        if(cols[i] == colMax) colMaxes.push_back(i);
    } 
    bool overlap = true;
    for(auto i = rowMaxes.begin(); i != rowMaxes.end() && overlap; i++){
        FOREACH(j, colMaxes){
            if(seen.find(pair<int, int>(*i,*j)) == seen.end()){ overlap = false; break;}
        }
    }
    if(overlap) cout <<rowMax + colMax -1 << endl;
    else cout << rowMax + colMax;
}