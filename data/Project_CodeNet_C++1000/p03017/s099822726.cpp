#include<iostream>

using namespace std;

int sqr[200005];

int main(){

    int N, A, B, C, D;
    bool doubleRock = false, tripleSqr = false;
    char S[200005];

    cin >> N >> A >> B >> C >> D ;

    for(int i=1; i<=N; i++){
        cin >> S[i] ;
    }

    sqr[0] = 1;
    for(int i=1; i<=N; i++){
        if(S[i] == '.') sqr[i] = 0;
        else sqr[i] = 1;

        if(((i < D) || (i < C)) && (i > A)){
            if((sqr[i] == 1 && sqr[i-1] == 1)){
                doubleRock = true;
            }
        }
        if(C > D){
            if((i > B) && (i <= D+1) ){
                if(sqr[i] == 0 && sqr[i-1] == 0 && sqr[i-2] == 0){
                    tripleSqr = true;
                }
            }
        }
    }

    if(doubleRock){
        cout << "No" << endl;
    } else{
        if(C < D){
            cout << "Yes" << endl;
        } else{
            if(tripleSqr == true){
                cout << "Yes" << endl;
            } else{
                cout << "No" << endl;
            }
        }
    }
    return 0;
}