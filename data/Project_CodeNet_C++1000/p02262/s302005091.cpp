#include <iostream>
#include <vector>
using namespace std;


#define pb push_back
#define rep(i, n) for(int i = 0; i < (n); ++i)


int insertionSort(int A[], int N, int g){
    int cnt = 0;
    for(int i = g; i < N; ++i){
        int v = A[i];
        int j = i - g;
        while(j >= 0 && A[j] > v){
            A[j + g] = A[j];
            j -= g;
            ++cnt;
        }
        A[j + g] = v;
    }
    return cnt;
}

int shellSort(int A[], int N, vector<int> &G){
    int h = 1;
    while(h <= N){
        G.pb(h);
        h = 3 * h + 1;
    }
    
    int cnt = 0;
    for(int i = G.size() - 1; i >= 0; --i)
        cnt += insertionSort(A, N, G[i]);
    
    return cnt;
}

int main(void){
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; ++i) cin >> A[i];
     
    vector<int> G;
    int cnt = shellSort(A, N, G);
    
    cout << G.size() << endl;
    for(int i = G.size() - 1; i > 0; --i){
        cout << G[i] << " ";
    }
    cout << G[0] << endl;
    cout << cnt << endl;
    rep(i, N) cout << A[i] << endl;
    
    return 0;
}
