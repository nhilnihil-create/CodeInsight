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
    double v[100];
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> v[i];
    }
    sort(v, v + N);
    double ans = (v[0] + v[1])/2;
    for(int i = 2; i < N; i++){
        ans = (ans + v[i]) /2;
    }
    cout << ans << endl;
    return 0;
}