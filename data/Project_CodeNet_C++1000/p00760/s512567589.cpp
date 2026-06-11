#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
int getday(int y,int m,int d){
    int cnt = 0;
    for(int ny = 1,nm = 1,nd = 1;ny != y || nm != m || nd != d;cnt++){
        nd++;
        //3の倍数の年ではない→奇数が20偶数が19
        //                 →常に20
        if(ny % 3 != 0 && nm % 2 == 0 && nd == 20){nd = 1;nm++;}
        if(nd == 21){nd = 1;nm++;}

        if(nm == 11){nm = 1;ny++;}
    }
    return cnt;
}
main(){
    int N;
    cin >> N;
    int level = getday(1000,1,1);
    int y3 = getday(4,1,1) - getday(1,1,1);
    rep(i,0,N){
        int y,m,d;
        cin >> y >> m >> d;
        int tmp = 0;
        if(y >= 4)tmp = ((y-1) / 3) * y3;
        y = y % 3;//４→１　５→２　６→３
        if(!y)y = 3;
        cout << level - getday(y,m,d) - tmp<< endl;
    }
}
