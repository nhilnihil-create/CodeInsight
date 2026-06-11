#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 1e9 + 7;

int main(){
    //input
    int N;
    cin >> N;
    int x[N];
    int y[N];
    int stat [N];
    int statx[N][N];
    int staty[N][N];
    REP(i,N){
        int a;
        cin >> a;
        stat[i] = a;
        REP(j,a){
            int c,d;
            cin >> c >> d;
            c--;
            statx[i][j] = c;
            staty[i][j] = d;
        }
    }

    //logic
    int key = 0;
    REP(i,(1<<N)){
        bool right = true;
        bool ans[N];
        bool T[N];
        int num = 0;
        REP(j,N){
            if(i & (1<<j)) T[j] = false;
            else{
                T[j]= true;
                num++;
            }
        }
        REP(j,N){
            ans[j] = true;
            if(T[j]){
                REP(k,stat[j]){
                    if(T[statx[j][k]]){
                        if(staty[j][k] == 0) ans[j] = false;
                    }
                    else{
                        if(staty[j][k] == 1) ans[j] = false;
                    }
                }
            }
            if(!ans[j]) right = false;
        }
        if(right){
            key = max(key,num);
        }
    }

    //answers
    cout << key << endl;
}