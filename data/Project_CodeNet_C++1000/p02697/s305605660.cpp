#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int INF = 1<<30;
const long long LINF = 1LL<<60;
const long long MOD = (long long)1e9 + 7;

int main(){
    int n, m, ans = 0;
    cin >> n >> m;
    if(n % 2 == 1){
        int c = n, t = 1;
        for(int i = 0; i < m; i++){
            cout << t << " " << c<< endl;
            t++;
            c--;
        }
    }else{
        int c = n, t = 1, u = m / 2;
        if(m % 2 == 0){
            u--;
        }
        for(int i = 0; i < m; i++){
            cout << t << " " << c<< endl;
            t++;
            c--;
            if(i == u){
                c--;
            }
        }
    }
}
