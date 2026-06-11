#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, num;
    cin >> N >> num;

    int number[103]={0};
    int now;
    for(int i=0; i<num; i++){
        cin >> now;
        number[now+1] = 1;
    }

    int width=0;
    int ans;
    while(true){
        if(num == 0){
            ans = N;
            break;
        }
        if(number[N-width+1] == 0){
            ans = N-width;
            break;
        }else if(number[N+width+1] == 0){
            ans = N+width;
            break;
        }

        width++;
    }

    cout << ans << endl;
}