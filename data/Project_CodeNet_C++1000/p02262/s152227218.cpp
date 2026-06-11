#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int m;
vector<int> G;
int insertionSort(int A[], int n, int g){
    int cnt = 0;
    for(int i=g; i<n; ++i){
        int v = A[i];
        int j = i - g;
        while(j>=0 && A[j]>v){
            A[j+g] = A[j];
            j -= g;
            cnt++;
        }
        A[j+g] = v;
    }
    return cnt;
}
int shellSort(int A[], int N){
    int cnt = 0;
    int x=3;
    int y=1;
    while(y <= N){
        G.push_back(y);
        x *= 3;
        y = (x-1)/2;
    }
    reverse(G.begin(), G.end());
    m = G.size();
    for(int i=0; i<m; ++i){
        cnt += insertionSort(A, N, G[i]);
    }
    return cnt;
}
int main(){
    int N; cin >> N;
    int A[1145149];
    for(int i=0; i<N; ++i) cin >> A[i];
    int res = shellSort(A, N);
    cout << m << endl;
    for(int i=0; i<m; ++i){
        if(i) cout << " ";
        cout << G[i];
        if(i == m-1) cout << endl;
    } 
    cout << res << endl;
    for(int i=0; i<N; ++i){
        cout << A[i] << endl;
    } 
    return 0;
}
