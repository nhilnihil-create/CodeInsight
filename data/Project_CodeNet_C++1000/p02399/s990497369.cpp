#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
    int a, b;
    scanf("%d %d", &a, &b); 

//    cin >> a >> b;
//    cin >> int a >> int b;
    int d = a / b; 
    int r = a % b;
    double f = (double)a/b;
//　明示的型変換（キャスト）

//    double f = 1.00 * a / b; 
//    cout << d << endl;
//    cout << r << endl;
//    cout << f << endl;
    printf("%d ", d);
    printf("%d ", r);
    printf("%.6lf\n", f);

    return 0;
}