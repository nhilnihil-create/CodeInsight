#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    int m ,d, count = 0;
    cin >> m >>d;
    for(int i = 1; i < m+1; i++){
        for(int j = 22; j < d+1; j++){
            if(((j/10)*(j%10)) == i && j%10 >= 2) {
                count++;
            }
        }
    }
    cout << count;
    return 0;
}
