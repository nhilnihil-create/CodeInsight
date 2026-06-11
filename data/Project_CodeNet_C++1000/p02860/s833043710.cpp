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
    ll N;
    string S;
    cin >>N>>S;
    if(N%2==1){
        cout << "No"<<endl;
    }else{
        rep(i,N/2){
            if(S[i] != S[i+N/2]){
                cout << "No"<<endl;
                break;
            }
            if(i == N/2-1){
                cout << "Yes"<<endl;
            }
        }
    }
    //cin >>N;
    
    
    

}