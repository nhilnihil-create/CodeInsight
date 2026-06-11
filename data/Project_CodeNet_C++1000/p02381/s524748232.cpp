#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
    int students;               //人数

    while( true )
    {
        double sum1 = 0, sum2 = 0;  //合計
        double ave = 0;             //平均
        double dev = 0;             //偏差

        cin >> students;

        if( students == 0 )
            break;

        double points[students];    //点数

        for( int i = 0; i < students; i++ )             //平均の計算
        {
            cin >> points[i];
            sum1 += points[i];
        }

        ave = sum1 / students;

        for( int i = 0; i < students; i++ )             //分散手前の計算
            sum2 += pow( (points[i] - ave), 2 );

        sum2 /= students;                               //分散

        dev = sqrt(sum2);                               //標準偏差

        cout << fixed;
        cout << setprecision(10) << dev << endl;
    }

    return 0;
}
