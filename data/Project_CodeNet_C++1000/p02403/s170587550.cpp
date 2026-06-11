// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_5_A&lang=jp


#include<iostream>
 using namespace std;

int main(){

 int H , W ;

    while(1)
 	{

    cin >> H >> W ;

 	    if ( H == 0 && W == 0 ){ //描画の終了条件
        break ;
        }else{
        // プログラムの処理を続行する
        }


        // 描画アルゴリズム
        // Y方向の描画
        for (int i = 0; i < H ; i = i + 1 )
        {

            //X方向の描画
            for (int j = 0; j < W ; j = j + 1 )
            {
            cout << "#" ;  //#の出力
            }
            cout << endl ; //改行

        }cout << endl ; //データセット間の改行



 	}

 return 0;

 }
