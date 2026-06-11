#include <bits/stdc++.h> 

using namespace std;

bool comparejobs(pair<int,int> j1, pair<int,int> j2) {
    if(j1.first == j2.first) {return j1.second < j2.second;}
    return j1.first < j2.first;
}


int main() {
    int N; cin >> N;
    vector<int> Numbs(N);
    int t1;
    int m1 = -1, ind1;
    for(int i = 0; i < N; ++i) {
        cin >> t1;
        Numbs[i] = t1;
        if(m1 < t1) {
            m1 = t1;
            ind1 = i;
        }
    }
    int m2 = -1;
    for(int i = 0; i < N; ++i) {
        if(Numbs[i] > m2 && i != ind1) {
            m2 = Numbs[i];
        }
    }
    
    for(int i = 0; i < N; ++i) {
        if(i != ind1) {
            cout << m1 << endl;
        }
        else{cout << m2 << endl;}
    }

}