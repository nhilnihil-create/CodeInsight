#include<iostream>
#include<string>
#include<vector>
#include<cstdio>

using namespace std;

bool isTurn[10];
int tate;
int yoko;
int max_cont;
int ban[11][10001];
void cont_senbei(int r);

int test = 0;

int main()
{
    for(;;){
        test = 0;
        max_cont = 0;
        int cont = 0;
        for(int i = 0; i < 10; i++){
            isTurn[i] = false;
        }
        cin >> tate >> yoko;

        if(tate == 0){
            break;
        }
        for(int i = 0; i < tate; i++){
            for(int j = 0; j < yoko; j++){
                cin >> ban[i][j];
                if(ban[i][j] == 0){
                    cont++;
                }
            }
        }
        max_cont = cont;                         //横を総当り
        for(int i = 0; i < tate; i++){
            cont_senbei(i);
            for(int j = 0; j < yoko; j++){
                if(ban[i][j] == 0){
                    ban[i][j] = 1;
                }
                else{
                    ban[i][j] = 0;
                }
            }
        }
        cout << max_cont << endl;
   //     cout << test << "回呼び出し" << endl;
        }
}
void cont_senbei(int r) {
    int cont = 0;
    int cont2 = 0;           //rをひっくり返す

    test++;

    isTurn[r] = true;           //ひっくり返せ

    for(int j = 0; j < yoko; j++){
        if(ban[r][j] == 0){
            ban[r][j] = 1;
        }
        else{
            ban[r][j] = 0;
        }
    }

    /***************************
    cout << "**********盤面*********" << endl;
    for(int i= 0; i < tate; i++){
        for(int j = 0; j < yoko; j++){
            printf("%d",ban[i][j]);
        }
        cout << endl;
    }
    cout << "************************" << endl;
    /****************************/

    //有効せんべいをカウント

    int yuko_senbei = 0;

    for(int i = 0; i < yoko; i++){
        for(int j = 0; j < tate; j++){
            if(ban[j][i] == 1){
                cont++;
            }
            else{
                cont2++;
            }
        }
        if(cont > (tate/2)){
            yuko_senbei += cont;
        }
        else{
            yuko_senbei += cont2;
        }

        cont = cont2 = 0;
    }

    //  cout << "有効せんべい:" << yuko_senbei << endl;

    //更新

    if(max_cont < yuko_senbei){
        max_cont = yuko_senbei;
    }

    for(int i = r; i < tate; i++){
        if(isTurn[i] == false){
 //           cout << i << "本目をひっくり返すよ" << endl;
            cont_senbei(i);
            isTurn[i] = false;
            for(int j = 0; j < yoko; j++){
                if(ban[i][j] == 0){
                    ban[i][j] = 1;
                }
                else{
                ban[i][j] = 0;
                }
            }
        }
    }
}