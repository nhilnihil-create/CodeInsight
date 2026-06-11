#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 8;

vector<char> aux;
vector<vector<char> > v;
char g[N][N], f[N][N];

void build(int pos, int h, int w){

    if(pos == h+w+1){
        v.push_back(aux);
        return;
    }
    aux.push_back('0');
    build(pos+1, h, w);
    aux.pop_back();

    aux.push_back('1');
    build(pos+1, h, w);
    aux.pop_back();

    return;
}

int main(){

    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int h, w, k; cin >>h >>w >>k;
    for(int i = 1; i<=h; i++){
        for(int j = 1; j<=w; j++){
            cin >>g[i][j];
        }
    }

    build(1, h, w);

    int ans = 0;
    for(int i = 0; i<v.size(); i++){

        for(int r = 1; r<=h; r++){
            for(int c = 1; c<=w; c++){
                f[r][c] = g[r][c];
            }
        }

        for(int r = 0; r<h; r++){
            if(v[i][r] == '1'){
                for(int x = 1; x<=w; x++){
                    f[r+1][x] = '*';
                }
            }
        }

        for(int c = h; c<h+w; c++){
            if(v[i][c] == '1'){
                for(int x = 1; x<=h; x++){
                    f[x][c-h+1] = '*';
                }
            }
        }

        int cnt = 0;
        for(int r = 1; r<=h; r++){
            for(int c = 1; c<=w; c++){
                cnt += (f[r][c] == '#');
            }
        }
        ans += (cnt == k);
    }

    cout <<ans <<endl;

    return 0;
}
