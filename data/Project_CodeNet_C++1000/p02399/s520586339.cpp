// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D&lang=jp

#include<iostream>
 using namespace std;

int main(){

    int a , b ;
    int d , r ;
    double da , db, f ;
    cin >> a >> b ;

    da = a ;
    db = b ;

    cout << fixed ;
    cout<< a / b << " " << a % b << " " << da / db << endl ;  
    return 0;

}
