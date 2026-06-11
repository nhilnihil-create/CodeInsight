#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int min(int a,int b){
    return a < b ? a : b;
}
int main(void){
    int N,M;
    cin >> N >> M;
    bool good_place[N+1];
    int H[N+1];
    for(int i=1;i<=N;i++)good_place[i] = true;
    for(int i=1;i<=N;i++){
        cin >> H[i];
    }
    for(int i=1;i<=M;i++){
        int A,B;
        cin >> A >> B;
        if(H[A] < H[B]){
            good_place[A] = false;
        }
        if(H[A] > H[B]){
            good_place[B] = false;
        }
        if(H[A] == H[B]){
            good_place[A] = good_place[B] = false;
        }
    }
    int ans = 0;
    for(int i=1;i<=N;i++){
        if(good_place[i]){
            ans++;
        }
    }
    cout << ans;
}