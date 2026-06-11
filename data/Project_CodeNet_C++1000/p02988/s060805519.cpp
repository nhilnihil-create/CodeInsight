#include <iostream>
#include <string>
using namespace std;
int main(void){
    int N;
    cin >> N;
    int p[N];
    for(int i=0;i<N;i++){
        cin >> p[i];
    }
    int ans = 0;
    for(int i=1;i+1<N;i++){
        int a,b,c;
        a = p[i-1];
        b = p[i];
        c = p[i+1];
        if((a < b && b < c) || (a > b && b > c)){
            ans++;
        }
    }
    cout << ans;
}
