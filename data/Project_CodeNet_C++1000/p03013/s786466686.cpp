#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include <iomanip>
using namespace std;
int main(){
    int N, M;
    int a[200000];
    cin >> N >> M;
    for (int i = 0; i < M; i++){
        cin >> a[i];
    }
    long long count[200000];
    int inc = 0;

    count[0] = 1;
    if(a[inc] == 1){
        count[1] = 0;
        inc++;
    }
    else{
        count[1] = 1;
    }


    for (int i = 2; i <= N; i++){
        if(i == a[inc]){
            count[i] = 0;
            inc++;
        }
        else{
            count[i] = count[i - 1] + count[i - 2];
            count[i] = count[i] % 1000000007;
        }
    }
    cout << count[N]  << endl;
    return 0;
}