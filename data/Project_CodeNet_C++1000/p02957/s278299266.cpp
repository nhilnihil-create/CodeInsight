#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<int,int> P;


int main(){
    int a,b;
    cin >> a >> b;
    int c = a-b;
    if(abs(c)%2==1){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        int i=0;
        while(true){
            if(abs(a-i)==abs(b-i)){
                cout << i<<endl;
                return 0;
            }
            i++;
        }
    }
    
    return 0;
}
