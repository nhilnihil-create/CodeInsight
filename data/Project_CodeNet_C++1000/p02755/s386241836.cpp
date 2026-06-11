#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<map>



using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

int a,b;

int main(){
    cin >> a >> b;
    rep(i,10001){
        if(i*8/100 == a && i*1/10 == b){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}