#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 550;
const long long mod = 1e9 + 7;

using namespace std;

int res[N][N];

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int n;
        cin >> n;
        int L = 0;
        while((1 << L) < n){
                L += 1;
        }
        for(int i = 0; i < L; i++){
                vector < int > A, B;
                for(int j = 0; j < n; j++){
                        if(j & (1 << i)){
                                A.push_back(j);
                        } else{
                                B.push_back(j);
                        }
                }
                for(int x: A){
                        for(int y: B){
                                if(!res[x][y]){
                                        res[x][y] = res[y][x] = i + 1;
                                }
                        }
                }
        }
        for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                        cout << res[i][j] << " \n"[j == n - 1];
                }
        }
}
