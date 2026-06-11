// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_5_B&lang=jp


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
        for (int i = 1; i <= H ; i = i + 1 )
        {

            //X方向の描画

            for (int j = 1; j <= W ; j = j + 1 )
            {
 

                if ( ( i + j ) % 2 == 0 ){
                cout << "#" ;
                }else{
                cout << "." ;
                }

                if ( j == W ){
                cout << endl ;   //行の最後の文字なら、改行する
                }
            }


        }
        
     cout << endl ; //データセット間の改行
 	}

 return 0;

 }
