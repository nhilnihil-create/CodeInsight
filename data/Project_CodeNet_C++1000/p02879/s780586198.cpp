#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define pb push_back
#define mod 1000000007
#define INF 2000000000
typedef long long ll;
bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}
// 入力



int main() {
     ll A,B;
    
    cin >>A>>B;
    if(A>9||B>9){
        cout << -1 << endl;
    }else{
        cout << A*B << endl;
    }
    
    //cout << N << endl;
    
    return 0;
}