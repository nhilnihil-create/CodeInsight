#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<iomanip>
#include<map>
#include<queue>
#include<cmath>
#include<cstdio>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define pai 3.1415926535897932384

using namespace std;
using ll =long long;
using P = pair<int,int>;

int main(int argc, const char * argv[]) {
    int N=0;
    int L[101];
    int Ans=0;

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> L[i];
    }

    sort(L, L+N);

    for(int i=0; i<N-2; i++){
        for(int j=i+1; j<N-1; j++){
            for(int k=j+1; k<N; k++){

                if(L[i]<L[j] && L[j]<L[k]){
                    int l = L[i] + L[j] + L[k];
                    int r = max(L[k], max(L[j], L[i]));

                    if(r<l-r) Ans++;
                }

            }
        }
    }

    cout << Ans << endl;

    return 0;
}