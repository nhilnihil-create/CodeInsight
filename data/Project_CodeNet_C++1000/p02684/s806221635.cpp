#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int64_t k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        int p;
        cin >> p;
        a.at(i) = p-1;
    }
    int town=0;
    set<int> visited;
    visited.insert(0);
    while(1){
        town = a.at(town);
        if(visited.count(town)){
            break;
        }
        visited.insert(town);
    }
    int roop_step=0;
    int roop_start = town;
    while(1){
        town = a.at(town);
        roop_step++;
        if(town == roop_start) break;
    }
    
    int to_start=0;
    town = 0;
    while(1){
        town=a.at(town);
        to_start++;
        if(town == roop_start) break;
    }

    int same_step;
    if(to_start > k){
        same_step = k;
    }
    else{
        same_step = (k-to_start)%roop_step + to_start;
    }

    int goal=0;
    for(int i=0; i<same_step; i++){
        goal = a.at(goal);
    }

    cout << goal+1 << endl;
}
