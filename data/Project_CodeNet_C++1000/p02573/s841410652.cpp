#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;

const int MAX = 200000;

class UFT{
public:
    UFT(int size){
        this->size = size;
        uft = new int[size];

        for(int i = 0;i < size;i++){
            uft[i] = -1;
        }
    }

    ~UFT(){
        delete uft;
    }

    int root(int n){
        if(n < 0 || n >= size)return -1;
        if(uft[n] == -1)return n;
        return uft[n] = root(uft[n]);
    }

    void unite(int a,int b){
        int aRoot = root(a);
        int bRoot = root(b);
        if(aRoot == bRoot)return;
        uft[aRoot] = bRoot;
    }
    
private:
    int size;
    int* uft;
};

int main(){
    int N,M;
    int A[MAX],B[MAX];

    cin >> N >> M;
    for(int i = 0;i < M;i++){
        cin >> A[i] >> B[i];
    }

    UFT uft(N);
    for(int i = 0;i < M;i++){
        uft.unite(A[i] - 1,B[i] - 1);
    }

    int cnt[MAX] = {0};
    int ans = 0;
    for(int i = 0;i < N;i++){
        cnt[uft.root(i)]++;
        ans = max(cnt[uft.root(i)],ans);
    }

    cout << ans << endl;

    return 0;
}
