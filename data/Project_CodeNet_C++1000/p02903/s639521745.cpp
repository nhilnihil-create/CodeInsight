#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int h, w, a, b, arr[1005][1005];
    memset(arr, 0, sizeof(arr));
    cin >> h >> w >> a >> b;
    for(int i=1; i<=b; i++){
        for(int j=1; j<=a; j++){
            arr[i][j]=1;
        }
    }
    for(int i=b+1; i<=h; i++){
        for(int j=a+1; j<=w; j++){
            arr[i][j]=1;
        }
    }
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cout << arr[i][j];
            if(j==w){
                cout << endl;
            }
        }
    }
    return 0;
}