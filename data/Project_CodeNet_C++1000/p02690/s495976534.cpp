#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int x;
    cin >> x;
    int ans_a=0,ans_b=0;
    for(int i=-200;i<200;i++){
        for(int j=-200;j<200;j++){
            if(pow(i,5)-pow(j,5)==x){
                ans_a=i;
                ans_b=j;
                break;
            }
        }
        if(ans_a!=0||ans_b!=0){
            break;
        }
    }
    cout << ans_a << " " << ans_b << endl;
}