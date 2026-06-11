#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define REP(i,n) for(int (i)=0; (i)<(n); (i)++)
#define For(i,a,b) for(int (i)=(a); (i)<(b); (i)++)

vector<int> G;
int m;
int cnt3;

void insertsort2(vector<int> &v, int N, int g) {
    for(int i = g; i < N; i++) {
        int w = v[i];
        int j = i - g;
        while (j >= 0 && v[j] > w) {
            v[j+g] = v[j];
            j -= g;
            cnt3++;
        }
        v[j+g] = w;
    }
}

void shellsort(vector<int> &v, int N) {
    cnt3 = 0;
    REP(i,m) {
        insertsort2(v, N, G[i]);
    }
}


int main() {
    int N;
    cin >> N;
    vector<int> v;
    REP(i,N) {
        int j;
        cin >> j;
        v.push_back(j);
    }
   
    m = (int)log2(v.size()) + 1;
    int l = 1;
    REP(i,m) {
        G.push_back(l);
        l *= 2;
    }
    reverse(G.begin(), G.end());
    shellsort(v, N);
    cout << m << endl;
    REP(i,G.size()-1) {
        cout << G[i] << " ";
    }
    cout << G[G.size()-1] << endl;
    cout << cnt3 << endl;
    REP(i,v.size()) {
        cout << v[i] << endl;
    }
    return 0;
}