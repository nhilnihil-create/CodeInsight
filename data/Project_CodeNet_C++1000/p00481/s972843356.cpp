#include <bits/stdc++.h>
using namespace std;

char c[1000];
int H, W, N, a, i, j, k, ns;
complex<int> chs[11];
bool kuk[1002][1002];
int score[1002][1002];
complex<int> mov[4] = {complex<int>(0, 1), complex<int>(1, 0), complex<int>(0, -1), complex<int>(-1, 0)};
queue<complex<int> > qu;
complex<int> now, nm;
bool flg1, flg2 = flg1 = true;

int main(){
    scanf("%d%d%d", &H, &W, &N);
    for(i = 1; i <= H; ++i){
        scanf("%s", c);
        for(j = 0; j < W; ++j){
            kuk[i][j + 1] = true;
            switch(c[j]){
                case 'X':
                    kuk[i][j + 1] = false;
                    break;
                case 'S':
                    chs[0] = complex<int>(i, j + 1);
                    break;
                default:
                    chs[c[j] - 48] = complex<int>(i, j + 1);
                    break;
            }
        }
    }
    for(i = 1; i <= N; i += 2){
        for(j = 0; j <= H + 1; ++j){
            for(k = 0; k <= W + 1; ++k){
                score[j][k] = 2147483647;
            }
        }
        qu.push(chs[i]);
        score[real(chs[i])][imag(chs[i])] = 0;
        flg1 = true;
        flg2 = (i + 1 <= N);
        while(flg1 || flg2){
            now = qu.front();
            ns = score[real(now)][imag(now)];
            for(j = 0; j < 4; j++){
                nm = now + mov[j];
                int x = real(now + mov[j]), y = imag(now + mov[j]);
                if(chs[i - 1] == nm){
                    flg1 = false;
                }
                if(i + 1 <= N && chs[i + 1] == nm){
                    flg2 = false;
                }
                if(kuk[x][y] && score[x][y] > ns + 1){
                    qu.push(nm);
                    score[x][y] = ns + 1;
                }
            }
            qu.pop();
        }
        a += score[real(chs[i - 1])][imag(chs[i - 1])];
        if(i + 1 <= N)a += score[real(chs[i + 1])][imag(chs[i + 1])];
        queue<complex<int> > emp;
        swap(qu, emp);
    }
    cout << a << endl;
    return 0;
}