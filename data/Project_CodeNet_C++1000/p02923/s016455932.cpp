#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<cmath>
using namespace std;

int main(){
    int N;
    cin >> N;
    int H[200000];
    int ans = 0;
    int counter = 0;
    for(int i = 0; i < N; i++){
        cin >> H[i];
    }
    for(int i = 0; i < N - 1; i++){
        if(H[i] >= H[i + 1]){
            counter++;
        }
        else{
            ans = max(ans, counter);
            counter = 0;
        }
    }
    ans = max(ans, counter);
    cout << ans << endl;
    return 0;
}