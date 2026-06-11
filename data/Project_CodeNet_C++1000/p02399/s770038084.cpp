#include <iostream>
#include <iomanip> // 追加
using namespace std;
 
int main(){
   int a, b;
   cin >> a >> b;
   cout << a/b << " " ;
   cout << a%b << " " << flush;
   // 小数点以下を6で固定
   cout << fixed << setprecision(6);
   // double に変換してから割る
   cout << (double)a/(double)b << endl;
}
