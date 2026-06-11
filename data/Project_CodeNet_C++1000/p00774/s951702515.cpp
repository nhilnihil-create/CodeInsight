#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<climits>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;
typedef pair<ll,ll> LLP;
#define INF 1000000007
#define MOD 1000000007

#define ARRAY_MAX 15

int d[ARRAY_MAX][ARRAY_MAX];
int arr[ARRAY_MAX];

int main(){

    int n;
    while(cin >> n,n){
        REP(i,ARRAY_MAX){
            REP(j,ARRAY_MAX){
                d[i][j] = 0;
            }
        }
        REP(i,n){
            REP(j,5){
                cin >> d[i][j];
            }
        }

        int ans = 0;

        while(1){

            bool exist = false;//消せるものがあるかどうか
            int cnt = 1;

            for(int i = n-1;i >= 0;i--){
                for(int j = 0;j < 5;j++){
                    if(j != 4 && d[i][j] == d[i][j+1]){
                        cnt++;
                    }else{
                        if(cnt >= 3 && d[i][j] != 0){//0で埋めたやつを考慮
                            ans += cnt*d[i][j];
                            exist = true;
                            for(int k = 0;k < cnt;k++){
                                d[i][j-k] = 0;//消したら0で埋める
                            }
                        }
                        cnt = 1;
                    }
                }
            }

            REP(hoge,n){
                for(int i = n-1;i > 0;i--){
                    for(int j = 0;j < 5;j++){
                        if(d[i][j] == 0 && d[i-1][j] != 0){
                            d[i][j] = d[i-1][j];
                            d[i-1][j] = 0;
                        }
                    }
                }
            }

        
            if(!exist){
                break;
            }
        }
        cout << ans << endl;
    }


    return 0;
}

