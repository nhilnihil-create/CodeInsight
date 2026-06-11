#include <bits/stdc++.h>
#define ll long long
#define ar array
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int M = 1e9+7;
const int N = 5*1e5;
vector<vector<char>> grid;
vector<vector<char>> tmp;
int h, w, k;

void do_paint(int i, int j){
    for(int x=0; x<h; x++){
        if((i>>x)&1){
            for(int y=0; y<w; y++)
                tmp[x][y] = 'R';
        }
    }

    for(int x=0; x<w; x++){
        if((j>>x)&1){
            for(int y=0; y<h; y++)
                tmp[y][x] = 'R';
        }
    }
}

int do_count(){
    int ans = 0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(tmp[i][j]=='#')
                ans++;
        }
    }
    return ans;
}


int main(){
    AC
    cin>>h>>w>>k;
    grid.resize(h);
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            char c;
            cin>>c;
            grid[i].push_back(c);
        }
    }

    int ans = 0;
    for(int i=0; i<(1<<h); i++){
        for(int j=0; j<(1<<w); j++){
            //cout<<i<<" "<<j<<endl;
            tmp = grid;
            do_paint(i, j);
            if(do_count()==k)
                ans++;
        }
    }
    cout<<ans<<endl;

}