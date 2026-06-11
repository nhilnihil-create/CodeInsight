#include <iostream>
using namespace std;
 
int main() {
    int n,m,a[101],b[101],ar,br,flag;
    while(1){
        flag = ar = br = 0;
        for(int i = 0;i < 101;i++){
            a[i] = b[i] = 0;
        }
        cin >> n >> m;
        if(n+m == 0)break;
        for(int i = 0;i < n;i++){
            cin >> a[i];
            ar += a[i];
        }
        for(int i = 0;i < m;i++){
            cin >> b[i];
            br += b[i];
        }
        if(ar < br || ar > br){
            for(int i = 0;i < n;i++){
                if(flag == 1)break;
                for(int j = 0;j < m;j++){
                    if(ar - a[i] + b[j] == br + a[i] - b[j]){
                        flag = 1;
                        cout << a[i] << " " <<b[j]<<endl;
                        break;
                    }
                }
            }
        }
        else if(ar == br){
            for(int i = 0;i < n;i++){
                if(flag == 1)break;
                for(int j = 0;j < m;j++){
                    if(a[i] == b[j]){
                        flag = 1;
                        cout << a[i] <<" "<<b[j]<<endl;
                        break;
                    }
                }
            }
        }
        if(flag == 0)cout << "-1" <<endl;
    }
    return 0;
}