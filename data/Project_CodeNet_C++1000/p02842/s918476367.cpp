#include<iostream>
#include<map>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    string ans = ":(";

    for(int i = 1; i <= 50000; i++){
        if((int) (i  * 1.08) == n){
            ans = to_string(i);
            break;
        }
    }

    cout << ans << endl;

}       