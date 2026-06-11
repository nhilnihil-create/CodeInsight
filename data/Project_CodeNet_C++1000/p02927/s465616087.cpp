#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    int m,d; cin >> m >> d;
    int c = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= d; j++){
            int d1 = j%10, d2 = j/10;
            if(d1 >= 2 && d2 >= 2 && i == d1*d2) c++;
        }
    }   
    cout << c << endl;
    return 0;
}