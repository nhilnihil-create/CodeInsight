#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main() {
    int N,M;
    cin >> N>>M;
    if(N%2==0){
        int preR=(int)((M+1)/2);
        int posR=(int)(M/2);
        REP(i,min(preR,M)) cout<<i+1<<" "<<preR*2-i<<endl;;
        REP(i,min(posR,M-preR)) cout<<preR*2+1+i<<" "<<N-i-1<<endl;        
    } else{
        REP(i,M){
            cout<<i+1<<" "<<M*2+1-(i+1)<<endl;
        }
    }
    return 0;
}