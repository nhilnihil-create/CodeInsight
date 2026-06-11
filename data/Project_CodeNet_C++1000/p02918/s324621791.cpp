#include <iostream>
#include <cstring>


using namespace std;

int main(){
    int N,K,i,j,lr,rl,happy;
    string q;
    while(cin >> N >> K){
        cin >> q;
        happy = 0;
        rl = 0;
        lr = 0;
        for(i = 1; i < q.length(); i++){
            if(q[i - 1] == q[i]) happy++;
            else if(q[i - 1] == 'R') rl++;
            else lr++;
        }
        for(j = 0; j < K; j++){
            if(lr && rl){
                lr--;
                rl--;
                happy += 2;
            }else if((lr == 0 && rl != 0) || (lr != 0 && rl == 0)){
                happy++;
                break;
            }else break;
        }
        cout << happy << endl;
    }
    return 0;
}