 #include<iostream>
 #include<string>
 #include<iomanip>
 #include<cmath>
 #include<math.h>

 #define rep(i,start,n) for(int i=0 ; i<n ; i++)

 using namespace std;

 int main(){

int a , b , C;
double S=0,h=0,c=0;
cin >> a >> b >> C;

S = 0.5 * a * b * sin(C * M_PI / 180);                               //??¢???
h = 2 * S / a;                                                       //??????
c = sqrt(a * a + b * b - 2 * a * b * cos(C * M_PI / 180));           //?????????????????????

cout << fixed << setprecision(8) << S << endl;                 //??¢?????¨???
cout << fixed << setprecision(8) << a+b+c << endl;            //??????????????¨???
cout << fixed << setprecision(8) << h << endl;                //????????¨???

return 0;

 }