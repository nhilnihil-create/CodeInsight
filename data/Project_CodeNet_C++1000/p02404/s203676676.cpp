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
 

                if ( j == W ){
                cout << "#" << endl ;   //行の最後の文字なら、#を描画して改行する
                } else if ( i == 1 ) {              
                cout << "#" ;           //最初の行なら、#を描画する
                } else if ( i == H ){
                cout << "#" ;           //最後の行なら、#を描画する
                } else if ( j == 1 ){
                cout << "#" ;           //行の最初の文字なら、#を描画する
                } else{
                cout << "." ;           //そうでないなら、.を描画する
                }

            }


        }
        
     cout << endl ; //データセット間の改行
 	}

 return 0;

 }
