#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define PI 3.14159265358979323846264338327950L
using namespace std;
using P = pair<int,int>;
using ll = long long;

int main(void){
    int a, b;
    cin >> a >> b;
    int komi1 = a*100*0.125;
    if(komi1*0.08 != a){komi1 += 1;}
    int mini = 1000000;
    if(komi1 / 10 == b){
        mini = min(mini, komi1);
    }
    
    int komi2 = b/0.1;
    if(komi2 * 8 /100 == a){
        mini = min(mini, komi2);
    }
    
    if(mini == 1000000){cout << -1 << endl; return 0;}
    cout << mini << endl;
    return 0;
}