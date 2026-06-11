#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int N;
    cin >> N;
    char c[N];
    for(int i=0;i<N;i++)cin>>c[i];
    int count_W = 0,count_R = 0;
    for(int i=0;i<N;i++){
        if(c[i] == 'W')count_W++;
        else count_R++;
    }
    int change = 0;
    int l = 0,r = N-1;
    while(l < r){
        if(c[l] == 'W' && c[r] == 'R'){
            change++;
            l++;
            r--;
        }
        else{
            if(c[l] != 'W'){
                l++;
            }
            if(c[r] !='R'){
                r--;
            }
        }
    }
    int ans = min(change,min(count_R,count_W));
    cout << ans << endl;
}
