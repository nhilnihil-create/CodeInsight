#include<bits/stdc++.h>
using namespace std;
#define pb push_back
;
int Q;
string S;
vector<char> from_head;
vector<char> from_tale;
bool order = true;  //文字追加方向
int T, F;
char C;

int main(){
    cin >> S;
    cin >> Q;

    for(int i = 0; i < Q; i++){
        cin >> T;
        if(T == 1) order = (order != true);
        else if(T == 2){
            cin >> F >> C;
            if(F == 1){
                if(order) from_head.pb(C);
                else from_tale.pb(C);
            }else if(F == 2){
                if(order) from_tale.pb(C);
                else from_head.pb(C);
            }
        }
    }

    
    int hlen = from_head.size();
    int tlen = from_tale.size();

    if(order){
        for(int i = hlen - 1; i >= 0; i--) cout << from_head[i];
        cout << S;
        for(int i = 0; i <= tlen - 1; i++) cout << from_tale[i];
        cout << endl;
    }else{
        for(int i = tlen - 1; i >= 0; i--) cout << from_tale[i];
        reverse(S.begin(), S.end()); cout << S;
        for(int i = 0; i <= hlen - 1; i++) cout << from_head[i];
        cout << endl;
    }
    
    return 0;
   
}

