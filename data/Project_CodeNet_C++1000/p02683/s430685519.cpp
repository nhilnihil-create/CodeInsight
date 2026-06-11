#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int, int> pairII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
#define long long ll;
#define shig_for(i, a, b) for(int i = (a); i < (b); ++i)
#define shig_rep(i, n) shig_for(i, 0, n)
#define shig_forB(bit,a,b) for(int bit = (a); bit < (1<<(b)); ++bit)
#define shig_repB(bit,n) shig_forB(bit,0,n)
#define tmp int temp = 0




int main()
{
    //cout << "Atcoder" << endl;
    int flag = -1;
    int N, M, X;
    cin >> N >> M >> X;
    int c[N] = {};
    
    VVI A(N);
    int cost_min = 10000000;
    
    shig_rep(i, N){
        cin >> c[i];
        shig_rep(j, M){
            tmp;
            cin >> temp;
            A[i].push_back(temp);
        }
    }
    
    shig_repB(bit,N){
        int cost = 0;
        int AA[M] = {};
        shig_rep(i, N){

            if( ((bit >> i) & 1) ){
                cost += c[i];
                shig_rep(j, M){
                    AA[j] += A[i][j];
                }
            }
        }

        int cnt = 0;
        shig_rep(j, M){
            if(AA[j] >= X)continue;
            else{
                cnt = -1;
                break;
            }
        }

        if(cnt == -1)continue;

        flag = 1;

        if(cost < cost_min){
            cost_min = cost;
        }

    }

    if(flag == -1){
        cout << -1 << endl;
    }else{
        cout << cost_min << endl;
    }

    return 0;
}