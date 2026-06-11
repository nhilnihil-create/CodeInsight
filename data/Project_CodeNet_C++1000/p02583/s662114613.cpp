#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
    int N;
    cin >> N;
    vector<int> L(N);
    rep(i,N){
        cin >> L.at(i);
    }
    sort(L.begin(),L.end());
    int i,j,k;
    int count = 0;
    for(i=0;i<N-2;i++){
        for(j=i+1;j<N-1;j++){
            for(k=j+1;k<N;k++){
                if(L.at(i) + L.at(j) > L.at(k) && L.at(i) != L.at(j) && L.at(j) != L.at(k)){
                    count++;
                }
            }
        }
    }

    cout << count << endl;
}