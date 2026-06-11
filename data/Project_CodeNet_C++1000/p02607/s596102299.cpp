#include <iostream>
using namespace std;
int main(void){
    int N;
    cin >> N;
    int a[N+1];
    for(int i=1;i<=N;i++)cin >> a[i];
    int ans = 0;
    for(int i=1;i<=N;i+=2){
        if(a[i] % 2 == 1){
            ans++;
        }
    }
    cout << ans << endl;
    
}
