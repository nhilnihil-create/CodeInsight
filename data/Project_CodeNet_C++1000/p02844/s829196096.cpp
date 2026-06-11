#include <iostream>
#include <string>
#define rep(i, n) for(int i=0;i<n;i++)
using namespace std;

int main(){
    int n;
    cin >> n;
    string v;
    cin >> v;
    int sum = 0;
    rep(i, 1000){
        int s[3] = {i/100, (i/10)%10, i%10};
        int f = 0;
        rep(j, n){
            if(v[j] == ('0' + s[f])){
                f++;
            }
            if(f == 3){
                sum++;
                break;
            }
        }
    }
    
    cout << sum << endl;

    return 0;
}