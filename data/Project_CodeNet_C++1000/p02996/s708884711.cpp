#include <bits/stdc++.h> 

using namespace std;

bool comparejobs(pair<int,int> j1, pair<int,int> j2) {
    return j1.second < j2.second;
}

int main() {
    int N; cin >> N;
    int t1, t2;
    vector<pair<int,int>> Jobs(N);
    for(int i = 0; i < N; ++i) {
        cin >> t1 >> t2;
        Jobs[i] = make_pair(t1,t2);
    }
    sort(Jobs.begin(), Jobs.end(), comparejobs);
    /*cout << endl << endl;
    for(int i = 0; i < N; ++i) {
        cout << Jobs[i].first << " " << Jobs[i].second << endl;
    }*/
    int sumi = 0;
    bool succ = true;
    for(int i = 0; i < N; ++i) {
        sumi += Jobs[i].first;
        if(sumi > Jobs[i].second) {succ = false;}
    }
    
    if(succ) {cout << "Yes";}
    else{cout << "No";}
}