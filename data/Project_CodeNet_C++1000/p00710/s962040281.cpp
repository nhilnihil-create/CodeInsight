#include <iostream>
using namespace std;

int main(){
    int card[51];
    int tmp[50];
    int n,r, from, num;

    while(1){
        cin >> n >> r;
        if(n == 0 && r == 0) break;
        for(int i=1; i<=n; i++){
            card[i]=n-i+1;
        }
        for(int i=0; i<r; i++){
            cin >> from >> num;
            for(int j=0; j<num; j++){
                tmp[j] = card[from+j];
            }
            for(int j=from-1; j>0; j--){
                card[j+num] = card[j];
            }
            for(int j=0; j<num; j++){
                card[j+1] = tmp[j];
            }
        }
        cout << card[1] << endl;
    }
        
    return 0;
}