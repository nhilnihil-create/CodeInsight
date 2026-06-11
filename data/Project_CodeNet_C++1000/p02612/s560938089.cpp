#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int num = 0;
    int ans = 0;
    if(10000>N){
        if(N%1000>0){
            num = (N/1000)+1;
            ans = num*1000-N;
        }else{
            ans = 0;
        }
    }else{
        if(N%1000>0){
            num = (N/1000)+1;
            ans = num*1000-N;
        }else{
            ans = 0;
        }
    }
    cout << ans << endl;
}