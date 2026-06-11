#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <functional>
#include <fstream>
#include <cstdlib>
typedef long long ll;
const int MOD = 1e9+7;


#define REP(i, N) for (int i = 0; i < (N); i++)
#define REPP(i, a, b) for (int i = (a); i < (b); i++)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define VSORT(c) sort((c).begin(),(c).end())
#define SZ(x) ((int)(x).size())
//vvintを作る　マクロで　 #define vvint(N,M) vector<vector<int>>

using namespace std;
int n;

void maxHeapify(int A[], int i){
    int l = i*2+1;
    int r = i*2+2;
    ll largest = 0;
    if(l < n && A[l] > A[i]){
        largest = l;
    }else{
        largest = i;
    }
    if(r < n && A[r] > A[largest]){
        largest = r;
    }
    if(largest != i){
        swap(A[i],A[largest]);
        maxHeapify(A,largest);
    }
}

void buildMaxHeap(int A[]){
    for(int i = n/2; i >= 0 ;i--){
        maxHeapify(A,i);
    }
}

int main(){
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    int A[n];
    for(int i = 0; i < n;i++){
        cin >> A[i];
    }
    buildMaxHeap(A);
    for(int i = 0; i < n;i++){
        cout << " " << A[i];
    }
    cout << endl;
    
    

    return 0;
}
