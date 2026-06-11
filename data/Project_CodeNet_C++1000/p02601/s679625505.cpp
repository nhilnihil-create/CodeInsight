#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<math.h>
#include<map>
using namespace std;
using ll = long long;
int main() {
    int a,b,c,K;
    bool flag = false;
    cin >> a >> b >> c >> K;
    for(int i=0;i<=K;i++){
        for(int j=0;j<=K;j++){
            for(int k=0;k<=K;k++){
                int x = a * (1 << i), y = b * (1 << j), z = c * (1 << k);
                if(i + j + k <= K && x < y && y < z) flag = true;
            }
        }
    }
    if(flag == true){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}