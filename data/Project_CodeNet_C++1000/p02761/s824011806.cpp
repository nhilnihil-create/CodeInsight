#include<bits/stdc++.h>
using namespace std;


int N, M, s, c;
bool exist = true;
vector<int> s_c(4, -1);  //s_c[i]=(左からi桁目の数)


int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> s >> c;
        if(s_c[s] >= 0 && s_c[s] != c){ exist = false; break; }
        if(s == 1 && c == 0){  //最上位桁が0
            if(N == 1) s_c[s] = 0;
            else { exist = false; break; }
        }
        s_c[s] = c;  //s_c[s] = -1 || s_c[s] == c
    }


    if(exist){
        for(int i = 1; i <= N; i++){
            if(s_c[i] < 0){            //最小となるように決定
                if(i == 1){    //最上位桁が決まっていない
                    if(N == 1) cout << 0;  
                    else cout << 1;
                }
                else cout << 0;        //最上位桁以外は0にすれば最小に
            }
            else cout << s_c[i];       //existかつもう決定している
        }  
        cout << endl;
    }
    
    else cout << -1 << endl;

    return 0;
}
