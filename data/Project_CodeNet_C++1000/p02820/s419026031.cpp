#include<bits/stdc++.h>
using namespace std;
using lint = long int;
#define pb push_back

int N, K;
int R, S, P;
int res = 0;
string T;


int rsp(char h, char& ch, int r, int s, int p){
    if(h == ch){ ch = '.'; return 0; }
    if(h == 's'){ ch = 's'; return r; }  //グーで勝ち
    else if(h == 'p'){ ch = 'p'; return s; }  //チョキで勝ち
    else if(h == 'r'){ ch = 'r'; return p; } //パーで勝ち
}


int main(){
    cin >> N >> K;
    cin >> R >> S >> P;
    cin >> T;

    for(int i = 0; i < K; i++){
        int head = i;
        char c = '.';  //K回後の相手の手
        while(head < N){ 
            res += rsp(T[head], c, R, S, P);
            head += K;
        }
    }

    cout << res << endl;
    return 0;
}
