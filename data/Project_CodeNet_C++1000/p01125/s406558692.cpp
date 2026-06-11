#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int N,M;
    cin >> N;
    while(N){
        set< P >st;
        int used = (1 << (N+1)) - 1;
        rep(i,0,N){
            int x,y;
            cin >> x >> y;
            st.insert(P(x,y));
        }
        cin >> M;
        int nx = 10,ny = 10;
        rep(i,0,M){
            char c;
            int num;
            cin >> c >> num;
            rep(j,0,num){
                if(c == 'N')ny++;
                if(c == 'S')ny--;
                if(c == 'E')nx++;
                if(c == 'W')nx--;
                if(st.count(P(nx,ny))){
                    st.erase(P(nx,ny));
                }   
            }
        }
        if(st.size() == 0) cout << "Yes" << endl;
        else               cout << "No" << endl;
        cin >> N;
    }
}
