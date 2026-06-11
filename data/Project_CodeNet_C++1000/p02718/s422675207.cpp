#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;


int main(){
    int N,M;
    cin >> N >> M;
    vector<int> A(N);
    int sum;
    rep(i,N){
        cin >> A[i];
        sum += A[i];
    }
    sort(A.rbegin(),A.rend());
    sum = accumulate(A.begin(),A.end(),0);

//   cout << sum/(4*M) << endl;
    rep(i,M){
        if(A.at(i)<(float)sum/(4*M)){
            cout << "No" << endl;
            return 0;
        }
    }
    

    cout << "Yes" << endl;

    

    
    
}