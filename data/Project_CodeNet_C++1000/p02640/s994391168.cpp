#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i <= (int)(n); i++)
int main(){
   
    int x,y;
    cin >> x >> y;
    rep(i,x){
        if(2*i+4*(x-i)==y){
            cout << "Yes  ";
            return 0;

        }
    }
    cout << "No" << endl;
 return 0;
}