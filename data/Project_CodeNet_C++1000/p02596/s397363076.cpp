#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;

const int MAX = 1000001;

int f(int N,int x){
    return ((x * 10) + 7) % N;
}

int main(){
    int N;
    bool check[MAX] = {false};

    cin >> N;

    int ans = 0;
    int x = 0;
    while(true){
        x = f(N,x);
        ans++;

        if(check[x] == true){
            ans = -1;
            break;
        }
        check[x] = true;

        if(x == 0){
            break;
        }
    }

    cout << ans << endl;

    return 0;
}