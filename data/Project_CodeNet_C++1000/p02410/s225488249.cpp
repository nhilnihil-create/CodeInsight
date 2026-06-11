#include<iostream>
using namespace std;

int main() 
{
    int n, m;

    cin >> n >> m;

    int a[n][m];                            //n行m列の配列を確保
    int b[m][1];                            //m行1列の配列を確保

    for( int i = 0; i < n; i++ )            //入力
        for( int j = 0; j < m; j++ )
            cin >> a[i][j];
    
    for( int i = 0; i < m; i++ )            //入力
        cin >> b[i][1];;

    for( int i = 0; i < n; i++ )
    {
        int sum = 0;                        //m行1列の値を格納する変数(これをm回計算して出力すればいい)
        for( int j = 0; j < m; j++ )
        {
            sum += a[i][j] * b[j][1];       //行列の計算
        }
        cout << sum << endl;
    }            
        
    return 0;
}
