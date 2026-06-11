#include <iostream>
using namespace std;
int main(void){
    int N;
    cin >> N;
    int a[N];
    for(int i=0;i<N;i++)cin>>a[i];
    int t=1;
    int ans=0;
    for(int i=0;i<N;i++){
        if(a[i] == t){
            t++;
        }
        else{
            ans++;
        }
    }
    if(ans == N)ans=-1;
    cout << ans << endl;
}
