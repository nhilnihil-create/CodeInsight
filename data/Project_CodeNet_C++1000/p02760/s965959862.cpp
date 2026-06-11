#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

const int MAX { 1000010 };
const ll MOD { 1000000007 };
const double PI = acos(-1.0);

int main(){
	ios::sync_with_stdio(false);
    map<int, ii> c;
    for(int i=0; i<3; ++i)
        for(int j=0; j<3; ++j){
            int aux;
            cin >> aux;
            c[aux] = make_pair(i, j);
        }

    int N;
    cin >> N;
    int cart[3][3] = {};
    while(N--){
        int aux;
        cin >> aux;
        if (c.find(aux) != c.end()){
            ii v = c[aux];
            cart[v.first][v.second] = 1;
        }
    }

    for(int i=0; i<3; ++i){
        int aux_i = 0, aux_j = 0;
        for(int j=0; j<3; ++j){
            aux_i += cart[i][j];
            aux_j += cart[j][i];
        }

        if(aux_i == 3 || aux_j == 3){
            cout << "Yes\n";
            return 0;
        }
    }

    int aux_dig_i = cart[0][0] + cart[1][1] + cart[2][2];
    int aux_dig_j = cart[2][0] + cart[1][1] + cart[0][2];
    if(aux_dig_i == 3 || aux_dig_j == 3){
        cout << "Yes\n";
        return 0;
    }   

    cout << "No\n";

    return 0;
}