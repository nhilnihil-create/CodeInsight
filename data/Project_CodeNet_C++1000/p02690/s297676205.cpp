#include <iostream>//cout<<right で右揃え
#include <iomanip>//cout<<setw(数字) で空白による桁揃え
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>//abs()で整数絶対値
#include <cmath>//abs()かfabs()で少数絶対値
#include <functional>//sort第三引数greater<型名>()で降順

using namespace std;
using ll = long long int;

int main(){
    ll X;cin>>X;
    bool end = 0;
    for(int i=-200;i<=200&&end!=1;i++){
        for(int j=-200;j<i;j++){
            if(pow(i,5)-pow(j,5)==X){
                cout << i << " " << j << endl;
                end = 1;
                break;
            }
        }
    }
    return 0;
}