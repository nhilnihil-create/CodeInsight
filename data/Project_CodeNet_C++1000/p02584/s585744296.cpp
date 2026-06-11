#include <iostream>//cout<<right で右揃え
#include <iomanip>//cout<<setw(数字) で空白による桁揃え
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <cstdlib>//abs()で整数絶対値
#include <cmath>//abs()かfabs()で少数絶対値
#include <functional>//sort第三引数greater<型名>()で降順
#include <map>

using namespace std;
using ll = long long int;

int main(){
    ll X,K,D;cin>>X>>K>>D;
    if(K<=(abs(X)/D)){
        cout << abs(X) - K * D << endl;
        return 0;
    }else{
        K -= abs(X) / D;
        X %= D;
        if(X<0){
            if(K%2==1) X += D;
        }else{
            if(K%2==1) X -= D;
        }
        cout << abs(X) << endl;
    }
    return 0;
}