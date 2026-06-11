#include<iostream>
using namespace std;

int main(){
    int n, x, h, i, j, ans;
    while(cin >> n >> x && n >= 3 && x >= 0){
        ans = 0;
        for(h = 1; h <= n - 2; h++){
            for(i = h + 1; i <= n - 1; i++){
                for(j = i + 1; j <= n; j++){
                   if(h + i + j == x)
                       ans++;
                }
            }
        }
        cout << ans << endl;
    }
}