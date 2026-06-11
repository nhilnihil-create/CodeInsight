#include <iostream>
#include <iomanip> // 追加
#include <cmath>  // 追加
using namespace std;

int main(){
double r;
cin>>r;  
double pi =acos(-1);// 円周率
cout<<fixed<<setprecision(6);
double area = r * r * pi;
double cir =(r+r) * pi;
cout<<area<<" "<<cir<<endl;
}
