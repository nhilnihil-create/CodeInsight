#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef  long long ll;

int main(void){
    int N;
    bool flag = false;
    cin >> N;

    for(int i = 0;i <= 9;i++){
        for(int j = 0;j <= 9;j++){
            if(i*j == N){
                flag = true;
                break;
            }
        }
    }
    
    if(flag)
        cout << "Yes" << endl;

    else
        cout << "No" << endl;
    
    return 0;
}