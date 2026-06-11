#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
using ll = int64_t;
using Graph = vector<vector<int> >;
const ll M = 1000000007;

int main(){
    int h,w,k;
    cin >> h >> w >> k;
    char c[h][w];
    int blacky[h];
    for(int i=0;i<h;i++) blacky[i]=0;
    int blackt[w];
    for(int i=0;i<w;i++) blackt[i]=0;

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> c[i][j];
            if(c[i][j]=='#') blacky[i]++;
        }
    }

    //for(int i=0;i<h;i++) cout << blacky[i] << ' ';
    //cout << endl;

    for(int i=0;i<w;i++){
        for(int j=0;j<h;j++){
            if(c[j][i]=='#') blackt[i]++;
        }
    }

    //for(int i=0;i<w;i++) cout << blackt[i] << ' ';
    //cout << endl;

    int sum=0;
    for(int i=0;i<h;i++) sum+=blacky[i];
    //cout << sum << endl;

    int cnt=0;
    for(int i=0;i<(1<<h);i++){
        int tmp=0;
        bitset<6> s(i);
        for(int p=0;p<h;p++){
            if(s.test(p)){
                tmp+=blacky[p];
            }
        }
        //cout << tmp << endl;

        for(int j=0;j<(1<<w);j++){
            bitset<6> t(j);
            int com=tmp;
            //cout << s << ' ' << t << endl;
            for(int q=0;q<w;q++){
                if(t.test(q)){
                    com+=blackt[q];

                    for(int k=0;k<h;k++){
                        if(s.test(k)){
                            if(c[k][q]=='#') com--;
                        }
                    }
                }
            }
            //cout << com << endl;
            if(sum-com==k) cnt++;
        }
        //cout << tmp << endl;
        //cout << endl;
    }
    
    cout << cnt << endl;
}