#include <iostream>
using namespace std;

int main(){
    int n;
    int d1[100],d2[100];
    int cun = 0;
    int ans = 0;

    cin >> n;
    for(int i = 0;i < n; i++){
        cin >> d1[i] >> d2[i];
    }
    for(int i = 0;i < n ;i++){
        if(d1[i] == d2[i]){
           cun++;
           if (cun >= 3){
               ans = cun;
               break;
           }
        }else{
           if(ans < cun) ans = cun;
           cun = 0;
        }
    }
    if (ans >= 3){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

return 0;
}