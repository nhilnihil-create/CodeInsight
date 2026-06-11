/* Headers */

#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int,pii> iii;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef priority_queue<pii, vector<pii>, greater<pii>> fila_prioridade;
typedef priority_queue<iii, vector<iii>, greater<iii>> fila_prioridade_grids;


#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)


/* -------------- */

//NAME: Power Socket
//Source: Atcoder Beginner Contest 139
//URL: https://atcoder.jp/contests/abc139
//TYPE: Ad-hoc
/* Knowledge required:

*/

//O único detalhe que deve ser lembrado é de subtrair a quantidade de tomadas
//totais em 1 para cada extensor.


int A,B;
int extensores = 0;
int tomadas = 1;

int main() {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        cin >> A >> B;


        while (tomadas < B) {
                tomadas += A - 1;
                extensores++;

        }

        cout << extensores << endl;

        return 0;
}

