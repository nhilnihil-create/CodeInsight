#include <iostream>
using namespace std;

int main(){
    int n,x;
    cin >> n >> x;    

    int l[n];
    for (int i=0;i<n;i++){
        cin >> l[i];
    }

    int d = 0;
    int ans = 1;

    for(int i=0;i<n;i++){
        d += l[i];
        if(d<=x){
            ans +=1;
        }else{
            break;
        }
    }
    cout << ans << endl;
}