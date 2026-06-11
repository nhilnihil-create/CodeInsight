#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m, p, c;
    while(cin >> n >> m){
        if(n * m == 0) break;
        vector<int> mou(n);
        for(int i = 0;i<n;i++) mou[i] = n-i;
        for(int i = 0;i<m;i++){
            vector<int> tmp(n);
            cin >> p >> c;
            for(int j = 0;j<c;j++){
                tmp[j] = mou[p+j-1];
            }
            for(int j = 0;j<p-1;j++){
                tmp[c+j] = mou[j];
            }
            for(int j = 0;j<p+c-1;j++){
                mou[j] = tmp[j];
            }
            // for(int j = 0;j<n;j++) cout << tmp[j];
            // cout << " ";
            // for(int j = 0;j<n;j++){cout << mou[j];}
            // cout << endl;
        }
        cout << mou[0] << endl;
    }
    return 0;
}
