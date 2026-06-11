#include <bits/stdc++.h>

#define pout(n)  printf ("%d\n", n)

#define rep(i,a,n) for (int i = a;i < n;i++)
#define per(i,n,a) for (int i = n-1;i >= a;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());

const int d4x[4] = {1, 0, -1, 0};
const int d4y[4] = {0, 1, 0, -1};
const int d8x[8] = { 1,1,0,-1,-1,-1,0,1 };
const int d8y[8] = { 0,1,1,1,0,-1,-1,-1 };

#define MAX_N (int)2e5+20
#define INF 1e12+20

typedef long long ll;
using namespace std;

ll cnt = 0;
int l;
int A[10000000];
vector<int> G;
void insertionSort(int A[],int n,int g){
    for (int i = g; i < n; i++){
        int v = A[i];
        int j = i-g;
        while(j >= 0 && A[j] > v){
            A[j+g] = A[j];
            j = j-g;
            cnt++;
        }
        A[j+g] = v;
    }
}

void shellSort(int A[],int n){
    for(int h =1;;){
        if(h > n) break;
        G.push_back(h);
        h = 3*h+1;
    }
    for(int i = G.size()-1; i >= 0; i--){
        insertionSort(A,n,G[i]);
    }
}

int n;
int main() {
    cin >> n;
    
    rep(i,0,n){
        cin >> A[i];
    }
    shellSort(A,n);

    cout << G.size() << endl;
    for(int i = G.size()-1; i >= 0; i--){
        printf("%d",G[i]);
        if(i) printf(" ");
    }
    printf("\n");
    printf("%lld\n",cnt);
    
    rep(i,0,n){
        pout(A[i]);
    }

    return 0;
}
