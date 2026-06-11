#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int inf=1E9;

int main(){
    int N;
    cin>> N;
    vector<int> a(N), b(N);

    rep(i,N){
        cin >> a[i] >> b[i];
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    if(N%2==1){
        cout << b[(N-1)/2] - a[(N-1)/2] +1 << endl;
    }
    else{
        cout << ((b[N/2]+b[N/2-1]) - (a[N/2]+a[N/2-1])) + 1 << endl;
    }
        
    return 0;
}
