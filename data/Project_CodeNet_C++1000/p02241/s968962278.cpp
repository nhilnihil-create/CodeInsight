#include<iostream>
#include<vector>
using namespace std;

enum color{WHITE, GRAY, BLACK};

int calc(vector<vector<int> >& G, vector<color>& state){
    int i_min = 0;
    int j_min = 0;
    for (int i = 0; i < G.size(); i++) {
        if (state[i] == WHITE || state[i] == BLACK) {
            continue;
        }
        bool is_black = true;
        for (int j = 0; j < G[i].size(); j++) {
            if (state[j] == WHITE){
                is_black = false;
                if (G[i][j] < G[i_min][j_min]) {
                    i_min = i;
                    j_min = j;
                }
            }
        }
        if (is_black) state[i] = BLACK;
    }
    state[j_min] = GRAY;
    return G[i_min][j_min];
}

int Prim(vector<vector<int> >& G) {
    vector<color> state(G.size(), WHITE);
    state[0] = GRAY;
    int ret = 0;

    for (int i = 0; i < G.size() - 1; i++) {
        ret += calc(G, state);
    }
    return ret;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int> > G(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> G[i][j];
            if (G[i][j] == -1) G[i][j] = 1e6;
        }
    }

    cout << Prim(G) << endl;

    return 0;
}