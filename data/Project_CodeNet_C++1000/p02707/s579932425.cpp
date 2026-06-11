#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N); //A[i]はiの上司を指す。
    A.at(0) = 0;
    for (int i = 1; i < N; i++) cin >> A.at(i); // [(0), 1, 1, 2, 2] 

    // 各上司について部下を求める。これには2次配列を用いる
    // 5人で、1 1 2 2 の場合、2と3の上司が1、4と5の上司は2となる。
    // [[2,3], [4,5], [], [], []]のような物を得たい。
    vector<vector<int>> B(N, vector<int>(0));

    /* for (int i = 1; i < N; i++){ 
(*_*; これでもできるがTLE ちょっとの改善でO(N)にできる!
        for (int j = 1; j <= N; j++){
            if (A.at(i) == j) B.at(j-1).push_back(i+1);
        }} */
    
    for (int i = 1; i < N; i++){ // iはAの添え字
        int boss = A.at(i);  // i+1番目の上司の番号はboss
        B.at(boss-1).push_back(i+1);  // こうすれば、O(N) !!
    }

    for (int i = 0; i < N; i++)
        cout << B.at(i).size() << endl;
}